import React, { useState } from "react";
import { BrowserRouter, Routes, Route } from "react-router-dom";
import ChangeSlot from "./Components/ChangeSlot"
import PastApplication from "./Components/PastApplication"
import Profile2 from "./Components/profile2"


function App() {

  return (
    <div>
      <BrowserRouter>
        <Routes>
          <Route path="/record" element={<PastApplication /> }></Route>
          <Route path="/profile" element={<Profile2 />}></Route>
          <Route path="/slot/change" element={<ChangeSlot/>}  ></Route>

        </Routes>
      </BrowserRouter>
    </div>
  );
}

export default App;
