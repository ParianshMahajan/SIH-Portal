import React, { useState, useEffect } from "react";
import { useNavigate } from "react-router-dom";
import axios from "axios";
import { api_url } from "../../config";
import { Divider, Typography } from "@mui/material";

const Teams = () => {
  const [data, setTeams] = useState([]);
  const navigate = useNavigate();
  const url = api_url + "/register/fetch";

  const fetchTeams = () => {
    axios
      .post(url, {
        message: "hi",
      })
      .then((res) => {
        if (res.data.status) {
          setTeams(res.data.Teams);
        }
      });
  };

  useEffect(() => {
    fetchTeams();
  }, []);

  return (
    <div className="wrapper">
      <div className="two" id="two">
        <h1
          id="registration"
          className="reg"
          style={{
            margin: "2% 0% 0% 0%",
            letterSpacing: "0px",
            fontWeight: "1500",
          }}
        >
          Available Teams
        </h1>
        <div
          className="regform"
          style={{
            display: "flex",
            float: "left",
            justifyContent: "start",
            margin: "-4.1% 5% 1% 4%",
          }}
        >
          <div className="formrow btcenter">
            <div className="container" id="container">
              <div className="hister">
                <button className="learn-more" onClick={() => navigate("/register")}>
                  <span className="circle" aria-hidden="true">
                    <span className="icon arrow"></span>
                  </span>
                  <span className="button-text">Home</span>
                </button>
              </div>
            </div>
          </div>
        </div>

          <Typography variant="h6" sx={{ mb:2,textAlign: "center",color:"white" }}>
            * To make a team visible here, go to the team details section
          </Typography>
        <div className="kuchbhi">
          <div className="leaderboardcont">
            <div className="team teamrow" style={{ border: "none", boxShadow: "none" }}>
              <div className="teamname tableHeader">TeamName</div>
              <div className="teamname tableHeader techStackHeading">Tech Stack</div>
              <div className="teamname tableHeader">Contact</div>
              <div className="pts tableHeader">Members</div>
              <div className="time tableHeader">Female Member</div>
            </div>
            <hr style={{width:"100%",border:"1px solid rgba(255, 255, 255, 0.69)",marginTop:"8px"}} />
            {data.map((e) => (
              <div className="team teamrow" key={e.TeamName}>
                <div className="teamname">{e.TeamName}</div>
                <div className="teamname techStackHeading">{e.TechStack}</div>
                
                <div className="teamname">{e.PhoneNumber}</div>
                <div className="pts">{`${e.Members.length}/6`}</div>
                <div className="time">{e.female ? "Yes" : "No"}</div>
              </div>
              
            ))}
          </div>
        </div>
      </div>
    </div>
  );
};

export default Teams;
