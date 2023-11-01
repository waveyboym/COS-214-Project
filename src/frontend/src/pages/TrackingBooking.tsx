import { faCheck } from "@fortawesome/free-solid-svg-icons";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import React, { useEffect, useState } from 'react';
import "../css/tracker.css";

type TrackingComponentProps = {
    orderStatus: string;
    date: string;
    emotionalState: string;
}

const TrackingBooking = (props: TrackingComponentProps) => {
    const [animationClass, setAnimationClass] = useState<string>("pulse"); // Initial animation class

    useEffect(() => {
        // Update animation class based on the emotional state
        if (props.emotionalState === "angry" || props.emotionalState === "slight angry") {
            setAnimationClass("pulse");
        } else {
            setAnimationClass(""); // Remove animation class for other emotional states
        }
    }, [props.emotionalState]);

    return (
        <section className='mt-4 mb-4'>
            <div className="container h-100">
                <div className="row d-flex justify-content-center align-items-center h-100">
                    <div className="col">
                        <div className="card card-stepper" style={{ borderRadius: "20px" }}>
                            <div className="card-body p-4">
                                <div className="d-flex justify-content-between align-items-center">
                                    <div className="d-flex flex-column">
                                        <span className="lead fw-normal">{props.orderStatus}</span>
                                        <span className="text-muted small">by Everest on {props.date}</span>
                                    </div>
                                    <div>
                                        <button className="btn btn-outline-primary" type="button">Track order details</button>
                                    </div>
                                </div>
                                <hr className="my-4" />

                                <div className="d-flex flex-row justify-content-between align-items-center align-content-center">
                                    <span className="dot"></span>
                                    <hr className="flex-fill track-line" /><span className="dot"></span>
                                    <hr className="flex-fill track-line" /><span className="dot"></span>
                                    <hr className="flex-fill track-line" /><span className="dot"></span>
                                    <hr className="flex-fill track-line" /><span
                                        className={`d-flex justify-content-center align-items-center big-dot dot ${animationClass}`}
                                    >
                                        <FontAwesomeIcon icon={faCheck} />
                                    </span>
                                </div>

                                <div className="d-flex flex-row justify-content-between align-items-center">
                                    <div className="d-flex flex-column align-items-start">
                                        <span>15 Mar</span>
                                        <span>Order placed</span>
                                    </div>
                                    <div className="d-flex flex-column justify-content-center">
                                        <span>15 Mar</span>
                                        <span>Order placed</span>
                                    </div>
                                    <div className="d-flex flex-column justify-content-center align-items-center">
                                        <span>15 Mar</span>
                                        <span>Order Dispatched</span>
                                    </div>
                                    <div className="d-flex flex-column align-items-center">
                                        <span>15 Mar</span>
                                        <span>Out for delivery</span>
                                    </div>
                                    <div className="d-flex flex-column align-items-end">
                                        <span>15 Mar</span>
                                        <span>Delivered</span>
                                    </div>
                                </div>

                                <div className="emotional-state">
                                    <p>Your emotional state: {props.emotionalState}</p>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </section>
    )
}

export default TrackingBooking;
