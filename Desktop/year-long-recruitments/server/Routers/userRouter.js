const express=require('express');
const { verify } = require('../middlewares/protect');
const { apply, sendData, createUser, updateProfile, pastApp, changeSlot } = require('../Controllers/UserFuncs');
const app=express();
const userRouter=express.Router();



//From frontend Questions and Links comes in array


//get route of /profile  is used for login as well as profile if logged in it will send data for the profile page 

userRouter
.route('/profile')
.get(verify,sendData)


//else if not loggedIn then /newuser 
userRouter
.route('/newuser')
.post(createUser)




//if some changes done while applying they will automatically merged in user profile
userRouter
.route('/apply')
.post(verify,apply)



//Setting to edit profile;
//clicking on setting
userRouter
.route('/edit')
.post(verify,updateProfile)




//Setting to edit profile;
//clicking on setting
userRouter
.route('/history')
.get(verify,pastApp)



//Setting to edit profile;
//clicking on setting
userRouter
.route('/slotchange')
.post(verify,changeSlot)










module.exports=userRouter;