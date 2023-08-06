import * as React from "react"


interface IHeaderProps {
}

interface IHeaderState {
}

class NavBar extends React.Component <IHeaderProps, IHeaderState> {
  render() {
    return (
      <>
  <nav className="bg-white border-gray-200 dark:bg-gray-900">
    <div className="flex flex-wrap justify-between items-center mx-auto max-w-screen-xl p-4">
      <a href="https://pomoclock.com" className="flex items-center">
        <img
          src="https://pomoclock.com/docs/images/logo.svg"
          className="h-8 mr-3"
          alt="Pomoclock Logo"
        />
        <span className="self-center text-2xl font-semibold whitespace-nowrap dark:text-white">
          Pomoclock
        </span>
      </a>
      <div className="flex items-center">
        <a
          href="#"
          className="text-sm  text-blue-600 dark:text-blue-500 hover:underline"
        >
          Login
        </a>
      </div>
    </div>
  </nav>
  </>
    )
  }
}

export default NavBar
