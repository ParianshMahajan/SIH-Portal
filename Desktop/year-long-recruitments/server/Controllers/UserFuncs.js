const express=require('express');
const app=express();
const cookieParser=require('cookie-parser');
app.use(cookieParser);
dotenv.config({ path: "./config.env" });

const jwt=require('jsonwebtoken');
const users = require('../models/users');
const application = require('../models/application');
const secret_key=config.env.Key;



module.exports.createUser= async function createUser(req,res){
try {
    let data=req.body; 

    //SSO
    //from SSO backend
    let token;
    //data gets manipulated
    //SSO
    let user=await users.create(data);
    

    res.json({
        status:true,
        token:token,
    });
    
} catch (error) {
    res.status(500).json({
        message:error.message,
        status:false
    })
}
    
}






module.exports.sendData= async function sendData(req,res){
    res.json({
        Users:res.user
    });
}   



module.exports.apply= async function apply(req,res){
    try{
        let data=req.body;
        
        //update if any changes applied while applying;
        let user=res.user;

        user.PhoneNumber=data.PhoneNumber;
        user.Branch=data.Branch;
        user.AboutMe=data.AboutMe;
        user.CG=data.CG;
        user.TechStack=data.TechStack;
        user.NonTech=data.NonTech;
        user.Links=data.Links;

        
        await user.save();




        //creating application
        let applic={
            UserId:user._id,
            AboutMe:user.AboutMe,   
            TechStack:user.TechStack,   
            NonTech:user.NonTech,   
            AboutMe:user.AboutMe,
            Slots:data.Slots,   
            WhyCCS:data.WhyCCS, 
            Links:data.Links,  
            Questions:data.Questions
        }
        let applied=await application.create(applic);
        user.Applications.push(applied._id);
        user.LastApplied=Date.now();

        await user.save();

    }
    catch(err){
        res.json({
            message:err.message
        })
    }
}







module.exports.updateProfile= async function updateProfile(req,res){
    try{
        let data=req.body;
        
        let user=res.user;
        
        user.PhoneNumber=data.PhoneNumber;
        user.Branch=data.Branch;
        user.AboutMe=data.AboutMe;
        user.CG=data.CG;
        user.TechStack=data.TechStack;
        user.NonTech=data.NonTech;
        user.Links=data.Links;

        await user.save();
        res.json({
            message:"Updated",
        })
    }
    catch(err){
        res.json({
            message:err.message
        })
    }
}






module.exports.pastApp= async function pastApp(req,res){
    try{
        let user=res.user;
        let apps=[];
        for(let i in user.Application){
            let app=await application.findOne({_id:user.Application[i]._id});
            apps.push(app);
        }


        res.json({
            status:true,
            Applications:apps,
            User:user,
        })

    }
    catch(err){
        res.json({
            message:err.message
        })
    }
}





module.exports.changeSlot= async function changeSlot(req,res){
    try{
        let data=req.body;
        let user=res.user;
        
        for(let i in user.Applications){
            let app=await application.findOne({_id:user.Applications[i]});
            if(app.Status==2){
                app.SlotRequest=data.SlotRequest;
                await app.save();
            }
        }


        res.json({
            message:"Request has been placed",
            status:true,
        })

    }
    catch(err){
        res.json({
            message:err.message
        })
    }
}



