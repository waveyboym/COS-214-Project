// Chakra imports
import { Portal, Box, useDisclosure, } from '@chakra-ui/react';
// Layout components
import Navbar from '../components/navbar/NavbarAdmin';
import React, { useState } from 'react';
import DashBoardUI from './DashBoardUI';
import "../css/dashboard.css";
import { ChakraProvider } from '@chakra-ui/react';
import theme from '../theme/theme';
import { ThemeEditorProvider } from '@hypertheme-editor/chakra-ui';

// Custom Chakra theme
export default function DashboardContainer(props) {
	const { ...rest } = props;
	// states and functions
	const [ fixed ] = useState(false);

	document.documentElement.dir = 'ltr';
	const { onOpen } = useDisclosure();
	document.documentElement.dir = 'ltr';
	return (
        <ChakraProvider theme={theme}>
            <ThemeEditorProvider>
                <Box>
                    <Box>
                        <Box
                            float='right'
                            minHeight='100vh'
                            height='100%'
                            overflow='auto'
                            position='relative'
                            maxHeight='100%'
                            w={{ base: '100%',}}
                            maxWidth={{ base: '100%',}}
                            transition='all 0.33s cubic-bezier(0.685, 0.0473, 0.346, 1)'
                            transitionDuration='.2s, .2s, .35s'
                            transitionProperty='top, bottom, width'
                            transitionTimingFunction='linear, linear, ease'>
                            <Portal>
                                <Box>
                                    <Navbar
                                        onOpen={onOpen}
                                        logoText={'Horizon UI Dashboard PRO'}
                                        brandText={"Admin"/*getActiveRoute(routes)*/}
                                        secondary={"manager"/*getActiveNavbar(routes)*/}
                                        message={""/*getActiveNavbarText(routes)*/}
                                        fixed={fixed}
                                        {...rest}
                                    />
                                </Box>
                            </Portal>

                            <Box mx='auto' p={{ base: '20px', md: '30px' }} pe='20px' minH='100vh' pt='50px'>
                                <DashBoardUI/>
                            </Box>
                        </Box>
                    </Box>
                </Box>
            </ThemeEditorProvider>
        </ChakraProvider>
	);
}
