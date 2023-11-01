import React, { useState, useEffect } from 'react';
import { useWaiterStore, usefoodProcessingTimeStore } from '../stateStore';
import { hero_bg } from '../assets';
import { EmotionalStateTab, Navbar, TrackingComponent } from '../components';

//when this page loads, it will make a socket request to the backend to get details about it's order(like all details)
const TrackingPage = () => {
  const [ratingVal, setRatingVal] = useState<number>(0);
  const [orderStatus, ] = useState<string>("");

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
        
        <TrackingComponent orderStatus={"Your order has been delivered"} date={new Date().toString()} />

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
          <h5 >Your order is ready!</h5>
        )}

      </div>
    </div>
  );
};

export default TrackingPage;
