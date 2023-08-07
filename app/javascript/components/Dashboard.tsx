import * as React from "react"

import Timer from "./Timer";

interface IDashboardProps {
}

const Dashboard: React.FC<IDashboardProps> = () => {
  return (
      <React.Fragment>
<div className="hero min-h-screen bg-base-auto">
  <div className="hero-content text-center">
    <Timer />
  </div>
</div>

      </React.Fragment>
  )
}

export default Dashboard
