import React, { useEffect, useState } from "react";
import { useNavigate } from 'react-router-dom';
import axios from "axios";
import { api_url } from "../../config";

const Members = () => {

  const [error, setError] = useState('')
  const [dispError, setDispError] = useState(false)
  const [joincode, form] = useState(true)
  const [loading, setLoader] = useState(false)
  const navigate = useNavigate();

  const [details, setDetails] = useState({})
  const [showMem, setShowMem] = useState(false)
  const [butt, showButt] = useState(false)
  const [mssg, showMssg] = useState(false)

  const url = api_url + '/register/login';
  const [data, setData] = useState({
    TeamName: "",
    Password: ""
  });

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
          console.log(res);
          if (res.data.status) {
            setLoader(false);
            setDetails(res.data)
            setDispError(false)
            form(false)
            setShowMem(true)
            if (res.data.Members.length === 6) {
              showButt(true);
            }
          } else {
            setLoader(false);
            setError(res.data.message || "Something went wrong");
            setDispError(true);
            form(true);
          }
        })
    } else {
      setDispError(true);
      setError(error);
    }
  }

  const url2 = api_url + '/register/login/submit';

  function submitTeam() {
    setShowMem(false);
    setLoader(true);
    axios.post(url2, {
      TeamName: details.TeamName,
    })
      .then(res => {
        if (res.data.status) {
          setLoader(false);
          setDispError(false);
          form(false);
          showMssg(true);
        } else {
          setLoader(false);
          setError(res.data.message || "Something went wrong");
          setDispError(true);
        }
      });
  }

  function handle(e) {
    const newdata = { ...data };
    newdata[e.target.id] = e.target.value;
    setData(newdata);

    if (e.target.id === 'TeamName') {
      if (e.target.value) {
        setDispError(false);
        setError("");
      } else {
        setDispError(true);
        setError("Please Enter all Fields");
      }
    }
  }

  return (
    <div className="wrapper">
      <div className="two" id="two">
        <h1 id="registration" className="reg" style={{ margin: "6% 0% 0% 0%", letterSpacing: "0px", fontWeight: "1500" }}>SIH</h1>

        {joincode &&
          <>
            <h1 id="registration" className=" regunder">REGISTRATION</h1>

            <div className="regform" style={{ display: "flex", float: "left", justifyContent: "start", margin: "-8% 5% 1% 4%" }} >
              <div className="formrow btcenter" >
                <div className="container" id="container">
                  <button className="learn-more" onClick={() => navigate('/register')}>
                    <span className="circle" aria-hidden="true">
                      <span className="icon arrow"></span>
                    </span>
                    <span className="button-text">Home</span>
                  </button>
                </div>
              </div>
            </div>

            <center style={{ marginTop: "10vh" }} className="regform">
              <form onSubmit={(e) => submit(e)}>
                <div className="formrow cntr" style={{ flexDirection: 'column' }}>
                  <input onChange={(e) => handle(e)} placeholder="Team Name" value={data.TeamName} type="text" id="TeamName" name="TeamName" required />
                  <input onChange={(e) => handle(e)} placeholder="Password" value={data.Password} type="text" id="Password" name="Password" required />
                </div>

                <button type="submit" className="join submit">
                  {"Submit"}
                </button>
              </form>
            </center>
          </>
        }

        {loading && 
          <div className='Loader'>
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
            <h1 id="registration" className="regunder">{details.TeamName}</h1>

            <div className="regform" style={{ display: "flex", float: "left", justifyContent: "start", margin: "-8% 5% 0% 4%" }}>
              <div className="formrow btcenter">
                <div className="container" id="container">
                  <button className="learn-more" onClick={() => navigate('/register')}>
                    <span className="circle" aria-hidden="true">
                      <span className="icon arrow"></span>
                    </span>
                    <span className="button-text">Home</span>
                  </button>
                </div>
              </div>
            </div>

            <div className="leaderboardcont" style={{ marginTop: "0%" }}>
              {details.Members.map((e) => {
                return (
                  <div className="team" key={e.PhoneNumber}>
                    <h5 className="teamname">{e.Name}</h5>
                    <h5 className="teamname">{(e.Gender === "Male" ? 'M' : 'F')}</h5>
                    <h5 className="teamname">{`+91 ${e.PhoneNumber}`}</h5>
                    <h5 className="pts">{`${e.TechStack}`}</h5>
                  </div>
                )
              })}
            </div>

            {details.submitted &&
              <div className='msg_contain' style={{ margin: "0% 0%", width: "100%" }}>
                <p style={{ color: 'white', fontSize: "40px" }}>Your team is already Submitted !!</p>
              </div>
            }

            {!details.submitted && butt &&
              <div className="buttccs" style={{ display: "flex", justifyContent: "center", width: "100%", marginTop: "-1%" }}>
                <button type="submit" className="join submit" onClick={() => submitTeam()}>
                  {"Submit"}
                </button>
              </div>
            }
          </>
        }

        {mssg &&
          <>
            <h1 id="registration" className="regunder" style={{ margin: "0% 0% 1% 0%", fontSize: "65px", fontWeight: "300" }}>{details.TeamName}</h1>

            <div className="regform" style={{ display: "flex", float: "left", justifyContent: "start", margin: "-8% 5% 0% 4%" }}>
              <div className="formrow btcenter">
                <div className="container" id="container">
                  <button className="learn-more" onClick={() => navigate('/register')}>
                    <span className="circle" aria-hidden="true">
                      <span className="icon arrow"></span>
                    </span>
                    <span className="button-text">Home</span>
                  </button>
                </div>
              </div>
            </div>

            <div className='msg_contain' style={{ margin: "10% 0%", width: "100%" }}>
              <div className="message">
                <p style={{ color: 'white', fontSize: "30px", fontFamily: "macer" }}>Your team has successfully submitted !!</p>
              </div>
            </div>
          </>
        }

      </div>
    </div>
  )
}

export default Members;
