const express=require('express')
const crypto=require('crypto')


const Team=require('../models/Team.js')
const User=require('../models/User.js')



module.exports.createTeam=async function createTeam(req,res){
    try {
        let data=(req.body)

        let TeamName=data.TeamName

        let leader={
            Name:data.Name,
            Email:data.Email,
            Password:data.Password,
            ConfirmPassword:data.ConfirmPassword,
            RollNumber:data.RollNumber,
            PhoneNumber:data.PhoneNumber,
            Branch:data.Branch,
            Year:data.Year,
            Role:"Leader",
            Gender:data.Gender,
            TeamName:TeamName,
            TechStack:data.TechStack
        }




        let Code=crypto.randomBytes(4).toString("hex");
          let url=`${req.protocol}://${req.get('host')}/register/:${Code}`


        let teamobj={
                TeamName:TeamName,
                Members:[],
                Password:data.Password,
                Code:Code
        }
        if(data.Gender=="Female"){
            teamobj.female=true;
        }

        let team=await Team.create(teamobj);
        let user=await User.create(leader);
        team.Members.push(user._id);
        await team.save();



        res.json({
            message:"Team Registered Successfully",
            status:true,
            Code:Code,
            URL:url,
            TeamName:TeamName
        });

    } catch (error) {
        res.json({
                status:false,
                message:error.message
        })
    }
}







module.exports.verifyTeam=async function verifyTeam(req,res){
    try {
        let data=req.body
        let team=await Team.findOne({Code:data.Code})

        if(team){
            if(team.Members.length<=5){
                res.json({
                    status:true,
                    url:`${req.protocol}://${req.get('host')}/register/:${team.Code}`,
                    TeamName:team.TeamName,
                    Code:data.Code
                })
            }
            else if(team.Members.length==6){
                res.json({
                    status:false,
                    message:"Team is Full !!"
                });
            }
        }
        else{
            res.json({
                status:false,
                message:"Invalid Team Code"
            });
        }
    } catch (error) {
        res.json({
                status:false,
                message:error.message
        })
    }
}












module.exports.info=async function info(req,res){
    try {
        let data=req.body;
        let team=await Team.findOne({Code:data.code})

        if(team){
            if(team.Members.length<=5){
                res.json({
                    status:true,
                    url:`${req.protocol}://${req.get('host')}/register/:${team.Code}`,
                    TeamName:team.TeamName,
                    Code:data.Code
                })
            }
            else if(team.Members.length==6){
                res.json({
                    status:false,
                    message:"Team is Full !!"
                });
            }
        }
        else{
            
            res.json({

                status:false,
                message:"Invalid URL"
            });
        }
    } catch (error) {
        res.json({
                status:false,
                message:error.message
        })
    }
}












module.exports.joinTeam=async function joinTeam(req,res){
    try {
        let data=(req.body)
        let Code=req.params.id.substring(1);
        let team=await Team.findOne({Code:Code})

        let member={
            Name:data.Name,
            Email:data.Email,
            Password:team.Password,
            RollNumber:data.RollNumber,
            PhoneNumber:data.PhoneNumber,
            Branch:data.Branch,
            Year:data.Year,
            Role:"Member",
            Gender:data.Gender,
            TeamName:team.TeamName,
            TechStack:data.TechStack,
        }

        if(data.Gender=="Female"){
            member.female=true;
        }


        let isFemale=false;
        team.Members.map((e)=>{
            if(e.Gender=='Female'){
                isFemale=true;
            }
        })


        let user;
        if(team.Members.length==5){
            if(isFemale){
                user=await User.create(member);
                team.Members.push(user._id)
                await team.save()
                res.json({
                    status:true,
                    message:"Member registered successfully",
                });
            }
            else{
                if(member.Gender=='Female'){
                    user=await User.create(member);
                    team.Members.push(user._id)
                    await team.save()
                    res.json({
                        status:true,
                        message:"Member registered successfully",
                    });
                }
                else{
                    res.json({
                        status:false,
                        message:"At least 1 female member is required",
                    });
                }
            }
        }
        else if(team.Members.length<5){
                user=await User.create(member);
                team.Members.push(user._id)
                await team.save()
                res.json({
                    status:true,
                    message:"Member registered successfully",
                });
        }
        

        

        

    } catch (error) {
        res.json({
                status:false,
                message:error.message
        })
    }
}











//Login Team Details

module.exports.login=async function login(req,res){
    try {
        let data=req.body
        let team=await Team.findOne({TeamName:data.TeamName})

        let users=await User.find({TeamName:data.TeamName})

        if(team){
            if(team.Password==data.Password){
                if(team.Submitted){
                    res.json({
                        status:true,
                        submitted:true,
                        Members:users,
                        TeamName:team.TeamName
                    });        
                }
                else{
                    res.json({
                        status:true,
                        submitted:false,
                        Members:users,
                        TeamName:team.TeamName
                    });                
                }
            }
            else{
                res.json({
                    status:false,
                    message:"Incorrect Password"
                });                
            }
        }
        else{
            res.json({
                status:false,
                message:"Team does not exists"
            });                
        }



    } catch (error) {
        res.json({
            status:false,
            message:error.message
        })
    }
}



//Submit team
module.exports.TeamSubmit=async function TeamSubmit(req,res){
    try {
        let data=req.body
        let team=await Team.findOne({TeamName:data.TeamName})



        if(team){
            team.Submitted=true;
            await team.save()
            res.json({
                status:true,
                submitted:true,
                message:"Team is submitted successfully"
            }) 
        }


    } catch (error) {
        res.json({
            status:false,
            message:error.message
        })
    }
}








module.exports.fetchTeams=async function fetchTeams(req,res){
    try {
        let teams=await Team.find({Submitted:false});
        teams=teams.filter((e)=>{
            if(e.Members.length!=6){
                return e;
            }
        })
        
        for(let i in teams){
            teams[i].female=false;
            for(let j in teams[i].Members){
                let user=await User.findOne({_id:teams[i].Members[j]});
                if(user.Gender=='Female'){
                    console.log("yayy");
                    teams[i].female=true;
                }
            }
        }
        console.log(teams);
                res.json({
                    status:true,
                    Teams:teams,
                })
    } 
    catch (error) {

        res.json({
            
                status:false,
                message:error.message
        })
    }

}






