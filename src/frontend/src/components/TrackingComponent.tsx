import { faCheck, faXmark } from "@fortawesome/free-solid-svg-icons";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import "../css/tracker.css";

type TrackingComponentProps = {
    orderStatus: string;
    date: string;
    waitTime: number;
    checkUpdate: () => void;
    checkMeOut: () => void;
}

const TrackingComponent = (props: TrackingComponentProps) => {
    return (
        <section className='mt-4 mb-5'>
            <div className="container h-100">
                <div className="row d-flex justify-content-center align-items-center h-100">
                <div className="col">
                    <div className="card card-stepper" style={{borderRadius: "20px"}}>
                    <div className="card-body p-4">

                        <div className="d-flex justify-content-between align-items-center">
                        <div className="d-flex flex-column">
                            <span className="lead fw-normal">Order status: {props.orderStatus}</span>
                            <span className="lead fw-normal">Expected prep time: {props.waitTime}</span>
                            <span className="text-muted small">by Everest on {props.date}</span>
                        </div>
                        <div>
                            { props.orderStatus === "completed" ?
                                <button className="btn btn-outline-primary" type="button" onClick={props.checkMeOut}>checkout</button>
                                :
                                <button className="btn btn-outline-primary" type="button" onClick={props.checkUpdate}>check on order</button>
                            }
                        </div>
                        </div>
                        <hr className="my-4"/>

                        <div className="d-flex flex-row justify-content-between align-items-center align-content-center">
                        <span className="dot"></span>
                        <hr className="flex-fill track-line"/><span className="dot"></span>
                        <hr className="flex-fill track-line"/><span className="dot"></span>
                        <hr className="flex-fill track-line"/><span className="dot"></span>
                        <hr className="flex-fill track-line"/><span
                            className="d-flex justify-content-center align-items-center big-dot dot">
                                {
                                    props.orderStatus === "completed" ?
                                    (<FontAwesomeIcon icon={faCheck} />)
                                    :
                                    <FontAwesomeIcon icon={faXmark} />
                                }
                            </span>
                        </div>

                        <div className="d-flex flex-row justify-content-between align-items-center">
                        <div className="d-flex flex-column align-items-start"><span>15 Mar</span><span>Order placed</span>
                        </div>
                        <div className="d-flex flex-column justify-content-center"><span>15 Mar</span><span>Order delivered to chefs</span></div>
                        <div className="d-flex flex-column justify-content-center align-items-center"><span>15
                            Mar</span><span>Order being prepared</span></div>
                        <div className="d-flex flex-column align-items-center"><span>15 Mar</span><span>Order complete</span></div>
                        <div className="d-flex flex-column align-items-end"><span>15 Mar</span><span>Waiters delivered to you</span></div>
                        </div>
                    </div>
                    </div>
                </div>
                </div>
            </div>
            </section>
    )
}

export default TrackingComponent