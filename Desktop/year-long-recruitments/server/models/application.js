const { mongoose } = require("mongoose");


const Schema = mongoose.Schema;
const application = new Schema({
    DateApplied: {
        type: Date,
        default: Date.now()
    },
    DateReviewed: {
        type: Date,
    },
    UserId:{
        type:Schema.ObjectId
    },
    Status: {
        type: Number,
        default:1
        // 1--> under process,
        // 2--> shortlisted for interview,
        // 3--> rejected
        // 4--> recruited
    },
    Links:[{
        type:String
    }],
    AboutMe: {
        type: String
    },
    TechStack: {
        type: String
    },
    NonTech: {
        type: String
    },
    Slots: {
        type: Array,
    },
    SlotRequest: {
        type: String,
        default:"NULL",
    },
    WhyCCS: {
        type: String
    },
    Questions:[{
        type:String
    }],
    AllotedSlot:{
        type:String
    }
});


module.exports = mongoose.model("applications", application);