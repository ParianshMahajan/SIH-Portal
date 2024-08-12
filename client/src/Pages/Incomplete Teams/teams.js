import React, { useState, useEffect } from "react";
import { useNavigate } from "react-router-dom";
import axios from "axios";
import { api_url } from "../../config";
import { Typography } from "@mui/material";

const Teams = () => {
  const [data, setTeams] = useState([]);
  const [showNoFemaleTeams, setShowNoFemaleTeams] = useState(false);
  const navigate = useNavigate();
  const url = api_url + "/register/fetch";

  const fetchTeams = () => {
    axios
      .post(url, { message: "hi" })
      .then((res) => {
        if (res.data.status) {
          setTeams(res.data.Teams);
        }
      });
  };

  useEffect(() => {
    fetchTeams();
  }, []);

  const handleCheckboxChange = (event) => {
    setShowNoFemaleTeams(event.target.checked||!showNoFemaleTeams);
  };

  const filteredTeams = showNoFemaleTeams
    ? data.filter((team) => !team.female)
    : data;

  return (
    <div className="wrapper">
      <div className="two" id="two">
        <h1 id="registration" className="reg">
          Available Teams
        </h1>
        <Typography variant="h6" className="typography-message">
          * To make a team visible here, go to the team details section
        </Typography>
        
        <div className="navigation">
          <button
            className="learn-more"
            onClick={() => navigate("/register")}
          >
            <span className="circle" aria-hidden="true">
              <span className="icon arrow"></span>
            </span>
            <span className="button-text">Home</span>
          </button>
        </div>
        
        <div className="team-list">
          <table className="leaderboardTable">
            <thead>
              <tr className="team teamrow">
                <th className="teamname tableHeader">Team Name</th>
                <th className="teamname tableHeader techStackHeading">Tech Stack</th>
                <th className="teamname tableHeader">Contact</th>
                <th className="pts tableHeader">Members</th>
                <th className="time tableHeader">
                  <input
                      type="checkbox"
                      id="filterNoFemales"
                      checked={showNoFemaleTeams}
                      onChange={handleCheckboxChange}
                      className="header-checkbox"
                  />
                  <p className="femMem" style={{padding:0,margin:0,cursor:"pointer"}} onClick={handleCheckboxChange}>
                    Female Member
                  </p>
                </th>
              </tr>
            </thead>
            <tbody>
              {filteredTeams.map((e) => (
                <tr className="team teamrow" key={e.TeamName}>
                  <td className="teamname">{e.TeamName}</td>
                  <td className="teamname techStackHeading">{e.TechStack}</td>
                  <td className="teamname">{e.PhoneNumber}</td>
                  <td className="pts">{`${e.Members.length}/6`}</td>
                  <td className="time">{e.female ? "Yes" : "No"}</td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      </div>
    </div>
  );
};

export default Teams;
