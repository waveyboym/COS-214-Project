import React, { useState, useEffect } from 'react';


interface TrackingPageProps {
  foodProcessingTime: number;
  waiterName: string;
  orderStatus: string;
}

const TrackingPage: React.FC<TrackingPageProps> = ({ foodProcessingTime, waiterName, orderStatus }) => {
  const [timeLeft, setTimeLeft] = useState(foodProcessingTime);

  useEffect(() => {
    if (foodProcessingTime > 0) {
      const interval = setInterval(() => {
        if (timeLeft > 0) {
          setTimeLeft(timeLeft - 1);
        }
      }, 1000);

      return () => clearInterval(interval);
    }
  }, [timeLeft, foodProcessingTime]);

  const handleRatingChange = (event: React.ChangeEvent<HTMLInputElement>) => {
    // Handle rating change logic here
    const rating = Number(event.target.value);
    // Update the rating in your state or send it to the backend
  };

  return (
    <div className="col-sm-6 col-lg-4 all fries">
      <h1>Order Tracking</h1>
      {foodProcessingTime > 0 ? (
        <div>
          <h2>Assigned Waiter: {waiterName}</h2>
          <h2>Time Remaining: {timeLeft} seconds</h2>

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
        <h2>Your order is ready!</h2>
      )}

      <div>
        <h2>Rate Your Experience (1 - 5)</h2>
        <input
          type="number"
          min="1"
          max="5"
          value={rating}
          onChange={handleRatingChange}
        />
      </div>
    </div>
  );
};

export default TrackingPage;
