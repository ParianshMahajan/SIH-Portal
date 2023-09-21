const { mongoose } = require("mongoose");
var validator = require("email-validator");
require('dotenv').config();


const Schema = mongoose.Schema;
const usersSchema = new Schema({
    ImgUrl: {
        type: String,
    },
    FirstName: {
        type: String
    },
    LastName: {
        type: String
    },
    AboutMe:{
        type: String
    },
    Email:{
        type:String,
        unique:true,
        validate:function(){
            return validator.validate(this.Email);
        }
    },
    PhoneNumber: {
        type: Number
    },
    Branch: {
        type: String
    },
    RollNumber: {
        type: Number,
    },
    CG: {
        type:String
    },
    TechStack:{
        type:String,
    },
    NonTech:{
        type:String,
    },
    Links:[{
        type:String
    }],
    LastApplied:{
        type:Date
    },
    Appications:[{
        type:Schema.ObjectId,
    }],
    Role:{
        type:String,
        default:"user"
    }
});

module.exports = mongoose.model("user", usersSchema);