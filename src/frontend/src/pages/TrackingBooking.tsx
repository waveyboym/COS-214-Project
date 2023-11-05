import { faCheck } from "@fortawesome/free-solid-svg-icons";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import React, { useEffect, useState } from 'react';
import {
    Box,
    Button,
    Center,
    Heading,
    HStack,
    Image,
    Text,
    VStack,
} from '@chakra-ui/react';
import { ChakraProvider } from '@chakra-ui/react';
// import theme from 'theme/theme';
import { ThemeEditorProvider } from '@hypertheme-editor/chakra-ui';

type TrackingComponentProps = {
    orderStatus: string;
    date: string;
    emotionalState: string;
    cartName: string;
    cartImage: string;
    waiterName: string;
};

const TrackingBooking = (props: TrackingComponentProps) => {
    const [animationClass, setAnimationClass] = useState<string>("pulse");
    const [isModalOpen, setIsModalOpen] = useState(false); // State to control the modal

    useEffect(() => {
        if (props.emotionalState === "angry" || props.emotionalState === "slight angry") {
            setAnimationClass("pulse");
        } else {
            setAnimationClass("");
        }
    }, [props.emotionalState]);

    const toggleModal = () => {
        setIsModalOpen(!isModalOpen);
    };

    function formatDate(inputDate: string) {
        const dateParts = inputDate.split("-");
        const year = dateParts[0];
        const month = dateParts[1];
        const day = dateParts[2];

        const months = [
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        ];

        const formattedDate = `${day} ${months[Number(month) - 1]} ${year}`;
        return formattedDate;
    }



    return (
        
    <ChakraProvider>
        <ThemeEditorProvider>
            <Center>
                <Box
                    borderRadius="20px"
                    boxShadow="lg"
                    p="4"
                    bgGradient="linear(to-b, rgba(0, 0, 0, 0), rgba(0, 0, 0, 0)), url('https://static.vecteezy.com/system/resources/previews/003/025/533/original/fast-food-delivery-cartoon-character-design-vector.jpg')"
                    backgroundSize="cover"
                    backgroundRepeat="no-repeat"
                >
                    <VStack spacing="4" align="stretch">
                        <Heading as="h2" size="md">
                        <Center><u> {props.orderStatus}</u></Center>
                        </Heading>
                        <Text fontSize="sm" color="gray.500">
                            by Everest on <Text as="u" display="inline" fontSize="sm">{props.date}</Text>
                        </Text>
                        <HStack spacing="4" justifyContent="flex-end">
                            <Button colorScheme="orange" onClick={toggleModal}>
                                Track order details
                            </Button>
                        </HStack>

                        <HStack spacing="4" alignItems="center">
                            <Box w="10px" h="10px" borderRadius="50%" bg="orange.400" />
                            <Box w="2px" h="2px" bg="yellow.400" flex="1" />
                            <Box w="10px" h="10px" borderRadius="50%" bg="orange.400" />
                            <Box w="2px" h="2px" bg="yellow.400" flex="1" />
                            <Box w="10px" h="10px" borderRadius="50%" bg="orange.400" />
                            <Box w="2px" h="2px" bg="yellow.400" flex="1" />
                            <Box
                                w="25px"
                                h="25px"
                                borderRadius="50%"
                                bg="yellow.400"
                                display="flex"
                                alignItems="center"
                                justifyContent="center"
                            >
                                <FontAwesomeIcon icon={faCheck} />
                            </Box>
                        </HStack>
                        <HStack spacing="4">
                            <VStack alignItems="start">
                                <Text>{formatDate(props.date)}</Text>
                                <Text><b><i>Order placed</i></b></Text>
                            </VStack>
                            <VStack>
                                <Text>{formatDate(props.date)}</Text>
                                <Text><b><i>Order in Kitchen</i></b></Text>
                            </VStack>
                            <VStack alignItems="center">
                                <Text>{formatDate(props.date)}</Text>
                                <Text><b><i>Order Dispatched</i></b></Text>
                            </VStack>
                            <VStack alignItems="center">
                                <Text>{formatDate(props.date)}</Text>
                                <Text><b><i>Out for delivery</i></b></Text>
                            </VStack>
                            <VStack alignItems="end">
                                <Text>{formatDate(props.date)}</Text>
                                <Text><b><i>Delivered</i></b></Text>
                            </VStack>
                        </HStack>
                        <Center>
                            <Text><b><i>Your emotional state: {props.emotionalState}</i></b></Text>
                        </Center>
                    </VStack>
                </Box>


                {isModalOpen && (
                    <Box
                        position="fixed"
                        top="0"
                        left="0"
                        w="100%"
                        h="100%"
                        bg={`rgba(0, 0, 0, 0.5)`}
                        zIndex="1"
                        overflow="hidden"
                    >
                        <Box
                            bg="white"
                            maxW="400px"
                            m="10% auto"
                            p="4"
                            borderRadius="10px"
                            position="relative"
                        >
                            <Heading as="h2" size="md">
                                <Center>
                                    Order Details
                                </Center>
                            </Heading>
                            <Text>Cart Name: {props.cartName}</Text>
                            <Center>
                                <img src={props.cartImage} alt="Cart Image" />
                            </Center>
                            <Text>Waiter Name:<i><b>{props.waiterName}</b></i> </Text>
                            <Button onClick={toggleModal}>Close</Button>
                        </Box>
                    </Box>
                )}

            </Center>
        </ThemeEditorProvider>
    </ChakraProvider>
    );
};

export default TrackingBooking;
