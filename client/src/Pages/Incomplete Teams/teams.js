import React, { useState, useEffect } from "react";
import { useNavigate } from 'react-router-dom';
import axios from "axios";
import { useCookies } from "react-cookie";
import { api_url } from "../../config";


const Teams = () => {
    const[data,setTeams]=useState([]);
    const navigate=useNavigate();
    const url = api_url + '/register/fetch';
   
    const fetchTeams=()=>{
      axios.post(url,{
        message:"hi"
      })
      .then(res => {
              console.log(res);
              if (res.data.status) {
                setTeams(res.data.Teams)
              }
            }
            )
    }


    useEffect(()=>{
        fetchTeams();
    },[])
    
        


  return(
      <div className="wrapper">
        <div className="two" id="two">
            <h1 id="registration" className="reg" style={{margin:"2% 0% 0% 0%",letterSpacing:"0px",fontWeight:"1500"}}>Available Teams</h1>
            <div className="regform" style={{display:"flex",float:"left",justifyContent:"start",margin:"-4.1% 5% 1% 4%"}}>
            <div className="formrow btcenter">
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
            <div className="leaderboardcont">{
                data.map((e)=>{
                  return(

                    <div className="team">
                        <h5 className="teamname">{e.TeamName}</h5>
                        <h5 className="pts">{`${e.Members.length}/6`}</h5>
                        <h5 className="time">{e.female?"Have F":"No F"}</h5>
                    </div>            
                      )
                }) 
            }
            </div>
        </div>
      </div>
  )

}

export default Teams
