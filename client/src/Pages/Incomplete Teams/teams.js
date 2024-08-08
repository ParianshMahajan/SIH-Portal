import React, { useState, useEffect } from "react";
import { useNavigate } from "react-router-dom";
import axios from "axios";
import { api_url } from "../../config";

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
        console.log(res);
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

        <div className="kuchbhi">
          <div className="leaderboardcont">
            <div className="team" style={{ border: "none", boxShadow: "none" }}>
              <div className="teamname">TeamName</div>
              <div className="teamname">Tech Stack</div>
              <div className="teamname">Contact</div>
              <div className="pts">Members</div>
              <div className="time">Female Member</div>
            </div>
            {data.map((e) => (
              <div className="team" key={e.TeamName}>
                <div className="teamname">{e.TeamName}</div>
                <div className="teamname">{e.TechStack}</div>
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
