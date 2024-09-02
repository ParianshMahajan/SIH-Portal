const mongoose = require("mongoose");
const dotenv = require("dotenv");

// INITIALIZING PATH TO .CONFIG FILE
dotenv.config({ path: "./config.env" });

// dotenv.config({ path: '../.env' });

const DB = process.env.DATABASE

mongoose
  .connect(DB)
  .then(function (i){
    console.log("Database Connected");
  })
  .catch(function (err) {
    console.log(err);
  });