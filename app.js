const express=require('express');
const fs = require('fs');
const path = require('path');
const cors=require('cors');
const cookieParser=require('cookie-parser');
const db=require('./config/db.js');
const userRouter = require('./routers/userRouter.js');
const dotenv = require("dotenv");
const app=express();



const https = require('https');

const options = {
  key: fs.readFileSync('privkey.pem'),
  cert: fs.readFileSync('cert.pem')
};

const server = https.createServer(options,app);


app.use(cors());
app.use(express.json());
app.use(cookieParser());  
app.use(express.static(path.join(__dirname, 'public')));

global.appRoot = path.resolve(__dirname);




app.use('/register',userRouter);








server.listen(process.env.PORT, '0.0.0.0', () => {
    console.log('Server running');
});
