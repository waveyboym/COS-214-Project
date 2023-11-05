const PromptModal = ({ onClose }: { onClose: () => void }) => {

    function handleNavigateToSplash(){
        window.location.href = '/';
        onClose();
    }
    return (
        <div className="modal">
            <div className="modal-content">
                <h2>Order Received</h2>
                <p>Your order is ready for checkout. Do you want to end game?</p>
                <button onClick={() => onClose()}>Cancel</button>
                <button onClick={() => handleNavigateToSplash()}>Proceed</button>
            </div>
        </div>
    );
};

export default PromptModal;
