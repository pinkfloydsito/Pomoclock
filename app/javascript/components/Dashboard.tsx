import * as React from "react"

interface IDashboardProps {
}

const Dashboard: React.FC<IDashboardProps> = () => {
  return (
      <React.Fragment>
<div className="hero min-h-screen bg-base-auto">
  <div className="hero-content text-center">
    <div className="max-w-md">
      <h1 className="text-5xl font-bold">25:00</h1>
      <div className="divider"></div>
      <button className="btn btn-primary text-2xl">Start</button>
    </div>
  </div>
</div>

      </React.Fragment>
  )
}

export default Dashboard
