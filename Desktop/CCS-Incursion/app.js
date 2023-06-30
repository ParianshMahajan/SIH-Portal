const express=require('express');
const fs = require('fs');
const cors=require('cors');
const cookieParser=require('cookie-parser');
const db=require('./config/db.js')


const app=express();
app.use(cors());
app.use(express.json());
app.use(cookieParser());  





const userRouter=require('./Routers/userRouter.js')


app.use('/register',userRouter);





const port = process.env.PORT || 7000;
const host = '127.0.0.1';

app.listen(port, host, () => console.log(`http://${host}:${port}`));
