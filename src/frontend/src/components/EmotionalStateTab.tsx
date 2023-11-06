import React, { useState } from 'react';
import { Box, Button, HStack, Heading, Center } from '@chakra-ui/react'; // Import Chakra UI components
import "../css/tracker.css";
import { ChakraProvider } from '@chakra-ui/react';
// import theme from 'theme/theme';
import { ThemeEditorProvider } from '@hypertheme-editor/chakra-ui';

type EmotionalStateTabProps = {
    emotionalState : string;
    setEmotionalState: (state: string) => void;
}

const EmotionalStateTab: React.FC<EmotionalStateTabProps> = ({emotionalState,  setEmotionalState }) => {

    const emotions = [
        { value: 'neutral', label: 'Neutral' },
        { value: 'angry', label: 'Angry' },
        { value: 'happy', label: 'Happy' },
        { value: 'slightly_angry', label: 'Slightly Angry' },
        { value: 'slightly_happy', label: 'Slightly Happy' },
    ];

    return (
        <ChakraProvider>
            <ThemeEditorProvider>
                <Center> {/* Use Center component to center the content */}
                    <div className="emotional-state">
                        <Center>
                        <Heading as="h3" size="md" mt="1"><u>How's the service? How you feeling?</u></Heading>
                        </Center>
                        
                        <HStack spacing="4"> {/* Use HStack to arrange buttons horizontally with spacing */}
                            {emotions.map((emotion) => (
                                <Button
                                    key={emotion.value}
                                    size="md"
                                    variant={emotionalState === emotion.value ? 'solid' : 'outline'}
                                    colorScheme="teal"
                                    onClick={() => setEmotionalState(emotion.value)}
                                >
                                    {emotion.label}
                                </Button>
                            ))}
                        </HStack>
                        <Center>
                        <Heading as="h6" size="sm" mt="6">I am: <u><i>{emotionalState}</i></u></Heading>
                        </Center>
                    </div>
                </Center>
            </ThemeEditorProvider>
        </ChakraProvider>
    );
};

export default EmotionalStateTab;
