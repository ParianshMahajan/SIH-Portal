import React, { useEffect, useState } from "react";
import { useNavigate, useParams } from 'react-router-dom';
import axios from "axios";
import { api_url } from "../../config";
import { Box, Button, Paper, Typography } from '@mui/material';
import CheckBoxIcon from '@mui/icons-material/CheckBox';
import CheckBoxOutlineBlankIcon from '@mui/icons-material/CheckBoxOutlineBlank';
import DeleteIcon from '@mui/icons-material/Delete';

const Members = () => {

  const [error, setError] = useState('')
  const [dispError, setDispError] = useState(false)
  const [create1, createError] = useState("Please Enter all Fields")
  const [joincode, form] = useState(true)
  const [loading, setLoader] = useState(false)
  const navigate = useNavigate();

  const [details, setDetails] = useState({})
  const [showMem, setShowMem] = useState(false)


  const url = api_url + '/register/login';
  const [data, setData] = useState({
    TeamName: "",
    Password: ""
  })

  const [checked, setChecked] = useState(false);
  const [isPending, setPending] = useState(false);
  async function handleClick(){
    setPending(true);
    try {
      const res = await axios.post(api_url + '/register/looking', {
        TeamName: details.TeamName,
        status: !checked
      });
      setChecked(!checked);
      setPending(false);      
    } 
    catch (error) {
      setPending(false);      
      console.log(error);
    }
      
  }



  const[showDisabled,setShowDisabled]=useState(false);

  function submit(e) {
    form(false);
    setLoader(true);
    e.preventDefault();
    if (!dispError) {


      axios.post(url, {
        TeamName: data.TeamName,
        Password: data.Password
      })
        .then(res => {
          if (res.data.status) {
            setLoader(false);
            setDetails(res.data)
            setChecked(res.data.submitted);
            setDispError(false)
            form(false)
            setShowMem(true)
            if(res.data.Members.length==6){
              setShowDisabled(true);
            }
            else{
              setShowDisabled(false);
            }
          }
          else {
            setLoader(false);
            if(res.data.message)
            setError(res.data.message);
            else
            setError("Something went wrong")
            setDispError(true)
            form(true);
          }
        }
        )
    }
    else {
      setDispError(true)
      setError(error);
    }

  }






  function handle(e) {
    const newdata = { ...data };
    newdata[e.target.id] = e.target.value;
    setData(newdata);

    if (e.target.id === 'TeamName') {
      if (e.target.value) {
        setDispError(false);
        setError("");
      }
      else {
        setDispError(true);
        setError(create1)
      }
    }
  }



  const handleRemoveMem=async(element)=>{
    try {
      const response = await axios.post(api_url + '/register/deleteMem', {
        Email: element.Email,
        TeamName: details.TeamName
      });
      if(response.data.status){
        setDetails(response.data);
        if(response.data.Members.length==6){
          setShowDisabled(true);
        }
        else{
          setShowDisabled(false);
        }
        if(response.data.isTeamDel){
          navigate('/register');
        }
      }

    } catch (error) {
      console.log(error);
    }

  }


  return (
    <div className="wrapper">
      <div className="two" id="two">

      <h1 id="registration" className="reg" style={{margin:"6% 0% 0% 0%",letterSpacing:"0px",fontWeight:"1500"}}>SIH</h1>
      

       
       
        {joincode &&
        <>
                 <h1 id="registration" className=" regunder" >REGISTRATION</h1>

        <div className="regform " style={{display:"flex",float:"left",justifyContent:"start",margin:"-8% 5% 1% 4%"}} >
          <div className="formrow btcenter " >
            <div className="container" id="container">
              <button class="learn-more " onClick={() => navigate('/register')}>
                <span class="circle" aria-hidden="true">
                  <span class="icon arrow"></span>
                </span>
                <span class="button-text">Home</span>
              </button>
            </div>
          </div>
        </div>


        <center style={{ marginTop: "10vh" }} className="regform"> 
          <form onSubmit={(e) => submit(e)}>
            <div className="formrow cntr" style={{flexDirection:'column'}}>
              <input onChange={(e) => handle(e)} placeholder="Team Name" value={data.TeamName} type="text" id="TeamName" name="TeamName" required />
              <input onChange={(e) => handle(e)} placeholder="Password" value={data.Password} type="password" id="Password" name="Password" required />
            </div>

            <button type="submit" className="join submit">
              {"Submit"}
            </button>
          </form>
        </center>
        </>
        }
       
       
        {loading && <div className='Loader'>
          <div className="loading"></div>
        </div>
        }
        
        
        {dispError &&
          <center>
            <p className='error'>{error}</p>
          </center>
        }






        {showMem &&
          <>

        <h1 id="registration" className="regunder" >{details.TeamName}</h1>

        
          <Box sx={{display:"flex",justifyContent:"center",width:1}} mb={2}>
            <button
                className="checkDisp"
                style={{background:checked ? "#00a1b1" : "",
                    opacity:isPending || showDisabled ?0.15:1,
                    pointerEvents: isPending || showDisabled  ? "none" : "initial"    
                } }
                onClick={() => {
                  handleClick();
                }}
                disabled={isPending || showDisabled }
                >
                  <p>
                    Looking.For.Members
                  </p>
                  {!checked ? <CheckBoxOutlineBlankIcon /> : <CheckBoxIcon />}
            </button>
        </Box>

        <div className="regform" style={{display:"flex",float:"left",justifyContent:"start",margin:"-8% 5% 0% 4%"}} >
          <div className="formrow btcenter" >
            <div className="container" id="container">
              <button class="learn-more" onClick={() => navigate('/register')}>
                <span class="circle" aria-hidden="true">
                  <span class="icon arrow"></span>
                </span>
                <span class="button-text">Home</span>
              </button>
            </div>
          </div>
        </div>

          <div className="leaderboardcont" style={{marginTop:"0%"}}>{
            details.Members.map((e)=>{
              return(

                <div className="team memberRow">
                        <h5 className="teamname" style={{width:"36%"}} >{e.Name}</h5>
                        <h5 className="teamname" style={{width:"36%"}}>{e.PhoneNumber}</h5>
                        <h5 className="teamname" style={{width:"8%"}} >{(e.Gender=="Male"?'M':'F')}</h5>
                        <button className="deleteIcon" onClick={()=>handleRemoveMem(e)}>
                          <DeleteIcon className="delicon" />
                        </button>
                    </div>                
                )
                }) 
              }
              </div>

        
          </>
        }


      </div>
    </div>
  )
}

export default Members;
