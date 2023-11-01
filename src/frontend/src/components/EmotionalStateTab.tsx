import React, { useState } from 'react';

type EmotionalStateTabProps = {
    setEmotionalState: (state: string) => void;
}

const EmotionalStateTab: React.FC<EmotionalStateTabProps> = ({ setEmotionalState }) => {
    const [emotionalState, setEmotionalStateLocal] = useState('neutral');

    const handleEmotionalStateChange = (event: React.ChangeEvent<HTMLSelectElement>) => {
        const selectedState = event.target.value;
        setEmotionalState(selectedState);
        setEmotionalStateLocal(selectedState);
    };

    return (
        <div className="emotional-state">
            <h3>How's the service? How you feeling?</h3>
            <div className="emotions">
                <select value={emotionalState} onChange={handleEmotionalStateChange}>
                    <option value="neutral">Neutral</option>
                    <option value="angry">Angry</option>
                    <option value="happy">Happy</option>
                    <option value="slightly_angry">Slightly Angry</option>
                    <option value="slightly_happy">Slightly Happy</option>
                </select>
            </div>
            <p>Your current emotional state: {emotionalState}</p>
        </div>
    );
};

export default EmotionalStateTab;
