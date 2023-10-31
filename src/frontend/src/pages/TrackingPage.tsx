import React, { useState, useEffect } from 'react';
import { useWaiterStore, usefoodProcessingTimeStore } from '../stateStore';
import { hero_bg } from '../assets';
import { Navbar } from '../components';
import "../css/tracker.css";


interface TrackingPageProps {
  orderStatus: string;
}

const TrackingPage: React.FC<TrackingPageProps> = ({ orderStatus }) => {
  const [ratingVal, setRatingVal] = useState<number>(0);

  const {foodProcessingTime, setFoodProcessingTime } = usefoodProcessingTimeStore((state) => { return { foodProcessingTime: state.foodProcessingTime, setFoodProcessingTime: state.setFoodProcessingTime }; });
  const {waiterName, setWaiterName } = useWaiterStore((state) => { return { waiterName: state.waiterName, setWaiterName: state.setWaiterName }; });

  useEffect(() => {
    if (foodProcessingTime > 0) {
      const interval = setInterval(() => {
        if (foodProcessingTime > 0) {
          setFoodProcessingTime(foodProcessingTime - 1);
        }
      }, 1000);

      return () => clearInterval(interval);
    }
  }, [foodProcessingTime]);

  const handleRatingChange = (event: React.ChangeEvent<HTMLInputElement>) => {
    // Handle rating change logic here
    const rating = Number(event.target.value);
    //setRatingVal(rating);
    // Update the rating in your state or send it to the backend
  };

  return (
    <div className="sub_page">
        <div className="hero_area">
          <div className="bg-box">
            <img src={hero_bg} alt="" />
          </div>
          <Navbar route={"Tracking"} />
        </div>
        <h1 style={{textAlign: "center"}}>Order Tracking</h1>
        <section className='mt-4 mb-4'>
          <div className="container h-100">
            <div className="row d-flex justify-content-center align-items-center h-100">
              <div className="col">
                <div className="card card-stepper" style={{borderRadius: "10px"}}>
                  <div className="card-body p-4">

                    <div className="d-flex justify-content-between align-items-center">
                      <div className="d-flex flex-column">
                        <span className="lead fw-normal">Your order has been delivered</span>
                        <span className="text-muted small">by DHFL on 21 Jan, 2020</span>
                      </div>
                      <div>
                        <button className="btn btn-outline-primary" type="button">Track order details</button>
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
                        <i className="fa fa-check text-white"></i></span>
                    </div>

                    <div className="d-flex flex-row justify-content-between align-items-center">
                      <div className="d-flex flex-column align-items-start"><span>15 Mar</span><span>Order placed</span>
                      </div>
                      <div className="d-flex flex-column justify-content-center"><span>15 Mar</span><span>Order
                          placed</span></div>
                      <div className="d-flex flex-column justify-content-center align-items-center"><span>15
                          Mar</span><span>Order Dispatched</span></div>
                      <div className="d-flex flex-column align-items-center"><span>15 Mar</span><span>Out for
                          delivery</span></div>
                      <div className="d-flex flex-column align-items-end"><span>15 Mar</span><span>Delivered</span></div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </section>
      <div className="col-sm-6 col-lg-4 all fries">
        {foodProcessingTime > 0 ? (
          <div>
            <h2>Assigned Waiter: {waiterName}</h2>
            <h2>Time Remaining: {foodProcessingTime} seconds</h2>

            <h2>Order Status:</h2>
            <div>
              <div className={`status-item ${orderStatus === 'Order Processed' ? 'pulse-animation' : ''}`}>
                Order Processed (Chef received the order)
              </div>
              <div className={`status-item ${orderStatus === 'Order Processing' ? 'pulse-animation' : ''}`}>
                Order Processing (Chefs cooking)
              </div>
              <div className={`status-item ${orderStatus === 'Order Ready' ? 'pulse-animation' : ''}`}>
                Order Ready (Food is ready)
              </div>
              <div className={`status-item ${orderStatus === 'Order Delivered' ? 'pulse-animation' : ''}`}>
                Order Delivered (Waiter delivered the food)
              </div>
              
            </div>
          </div>
        ) : (
          <h2 >Your order is ready!</h2>
        )}



        <div className=''>
          <h2>Rate Your Experience (1 - 5)</h2>
          <input
            type="number"
            min="1"
            max="5"
            value={ratingVal}
            onChange={handleRatingChange}
          />
        </div>
      </div>
    </div>
  );
};

export default TrackingPage;
