const mongoose=require('mongoose');
const validator=require('email-validator')

const userSchema = new mongoose.Schema({
    Name:{
        type:String,
        required:true
    },
    Email:{
        type:String,   
        required:true,
        unique:true,
        validate:[function(){
            return validator.validate(this.Email);
        },"Invalid Email"]
    },
    Room: {
        type: String,
    },
    Password:{
        type:String,
        required:true,
        minLength:[8,"Password must contain at least 8 letters"]
    },
    ConfirmPassword:{
        type:String,
        required:true,
        minLength:8,
        validate:[function(){                                                               
            //Confirming Password....
            return this.ConfirmPassword==this.Password;
        },"Password din't match..."]
    },
    PhoneNumber:{
        type:Number,
        required:true,
    },
    RollNumber:{
        type:Number,
        required:true,
        unique:[true,"Roll Number must be unique"]
    },
    Role:{
        type:String,
        enum:['Leader','Member'],
        default:'Member'
    },
})


userSchema.pre('save',function(){
    this.ConfirmPassword=undefined;
});

const User = mongoose.model('User', userSchema);

module.exports= User;