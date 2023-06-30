const express=require('express')
const Team=require('../models/Team.js')
const User=require('../models/User.js')


const userRouter=express.Router();


userRouter
.route('/')
.post(uploadData)


async function uploadData(req,res){
    try {
        let data=(req.body).arr
        
        let TeamName=data[0]
        let Password=data[1]
        let ConfirmPassword=data[2]
        let Room=data[3]

        let userids=[];




        for(let i=4;i<data.length();i++){
            let obj=data[i];
            
            if(i==4){
                obj.Role="Leader";
            }

            obj.Password=Password;
            obj.ConfirmPassword=ConfirmPassword;
            obj.Room=Room;
            let user=await User.create(obj);
            
            userids.push(user._id)
        }




        let teamobj={
            TeamName:TeamName,
            Members:userids,
            Room:Room
            }

        let team=await Team.create(teamobj);




        res.json({
            message:"User Registered Successfully"
        });
    } catch (error) {
        res.status(500).json({
            message:error.message
        })
    }
}


module.exports=userRouter;
