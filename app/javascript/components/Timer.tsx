import * as React from "react"

import { useInterval } from 'usehooks-ts'

interface ITimerProps {
}

const delay = 1000
const Timer: React.FC<ITimerProps> = () => {
    const [count, setCount] = React.useState<number>(25*60)
    const [isPlaying, setPlaying] = React.useState<boolean>(false)

    useInterval(
      () => {
        setCount(count - 1)
      },
      isPlaying ? delay : null,
    )

    React.useEffect(() => {
        if(count <= 0) {
            setPlaying(false)
        }
    }, [count])

    const toggleCounter = () => {
        if(!isPlaying) {
            setPlaying(true)
        } else {
            setPlaying(false)
        }
    }

    const formatCount = (count: number) : String => {
        if(count<=0) return "00:00"

        const timeString = new Date(count * 1000).toLocaleTimeString([], {
          minute: "numeric",
          second: "2-digit",
        })

        return timeString
    }

    const valueBtn = React.useMemo(() => {
        return isPlaying ? "Pause" : "Start"
    }, [isPlaying])

  return (
    <div className="max-w-md">
      <h1 className="text-5xl font-bold">{formatCount(count)}</h1>
      <div className="divider"></div>
      <button 
      className="btn btn-primary text-2xl"
      onClick={() => toggleCounter()}
      
      >{valueBtn}</button>
    </div>
  )
}

export default Timer
