const mongoose = require('mongoose');
const dotenv = require('dotenv');


// dotenv.config({ path: '../.env' });

// const DB = process.env.DATABASE
// // .replace(
// //   '<username>',
// //   process.env.username
// // )
// // .replace(
// //   '<password>',
// //   process.env.password
// // );

const url="mongodb+srv://parianshm:21234018@intrusion.nwbko8s.mongodb.net/?retryWrites=true&w=majority"

mongoose
.connect(url)
.then(function(i){
    console.log('Database Connected');
})
.catch(function(err){
    console.log(err);
})



