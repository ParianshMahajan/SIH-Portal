const mongoose=require('mongoose');

const TeamSchema = mongoose.Schema({
    TeamName: {
        type: String,
        required: true,
        unique:[true,"Team Name already used by someone else"]
    },
    Members: {
        type: Array,
        required: true
    },
    Questions: {
        type: Array,
    },
    Room: {
        type: String,
    },
    Position: {
        type: Number,
    }
})
let Team = mongoose.model('Team', TeamSchema);

module.exports=Team;
