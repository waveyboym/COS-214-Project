import React, { useState } from 'react';
import { RouteComponentProps, Route, Routes, Navigate } from 'react-router-dom';
import routes from '../../routes';
import { Box, useDisclosure } from '@chakra-ui/react';
import Navbar from '../../components/Navbar';
import Sidebar from '../../components/sidebar/Sidebar';
import SidebarContext from '../../contexts/SidebarContext';

interface RouteType {
  layout: string;
  path: string;
  component: React.ComponentType;
  items?: RouteType[];
  collapse?: boolean;
  category?: boolean;
  name: string;
  secondary: string;
  messageNavbar: string;
}

interface DashboardProps {
  location: RouteComponentProps['location'];
}

const Dashboard: React.FC<DashboardProps> = (props) => {
  const { location } = props;
  const [fixed] = useState(false);
  const [toggleSidebar, setToggleSidebar] = useState(false);

  const getRoute = (): boolean => {
    return location.pathname !== '/admin/full-screen-maps';
  };

  const getActiveRoute = (routes: RouteType[]): string => {
    let activeRoute = 'Default Brand Text';

    for (let i = 0; i < routes.length; i++) {
      if (routes[i].collapse) {
        let collapseActiveRoute = getActiveRoute(routes[i].items || []);
        if (collapseActiveRoute !== activeRoute) {
          return collapseActiveRoute;
        }
      } else if (routes[i].category) {
        let categoryActiveRoute = getActiveRoute(routes[i].items || []);
        if (categoryActiveRoute !== activeRoute) {
          return categoryActiveRoute;
        }
      } else {
        if (location.href.indexOf(routes[i].layout + routes[i].path) !== -1) {
          return routes[i].name;
        }
      }
    }
    return activeRoute;
  };

  const getActiveNavbar = (routes: RouteType[]): boolean => {
    let activeNavbar = false;

    for (let i = 0; i < routes.length; i++) {
      if (routes[i].collapse) {
        let collapseActiveNavbar = getActiveNavbar(routes[i].items || []);
        if (collapseActiveNavbar !== activeNavbar) {
          return collapseActiveNavbar;
        }
      } else if (routes[i].category) {
        let categoryActiveNavbar = getActiveNavbar(routes[i].items || []);
        if (categoryActiveNavbar !== activeNavbar) {
          return categoryActiveNavbar;
        }
      } else {
        if (location.href.indexOf(routes[i].layout + routes[i].path) !== -1) {
          return routes[i].secondary === 'true';
        }
      }
    }
    return activeNavbar;
  };

  const getActiveNavbarText = (routes: RouteType[]): string => {
    let activeNavbar = '';

    for (let i = 0; i < routes.length; i++) {
      if (routes[i].collapse) {
        let collapseActiveNavbar = getActiveNavbarText(routes[i].items || []);
        if (collapseActiveNavbar !== activeNavbar) {
          return collapseActiveNavbar;
        }
      } else if (routes[i].category) {
        let categoryActiveNavbar = getActiveNavbarText(routes[i].items || []);
        if (categoryActiveNavbar !== activeNavbar) {
          return categoryActiveNavbar;
        }
      } else {
        if (location.href.indexOf(routes[i].layout + routes[i].path) !== -1) {
          return routes[i].messageNavbar;
        }
      }
    }
    return activeNavbar;
  };

  document.documentElement.dir = 'ltr';
  const { onOpen } = useDisclosure();
  document.documentElement.dir = 'ltr';

  return (
    <Box>
      <Box>
        <SidebarContext.Provider
          value={{
            toggleSidebar,
            setToggleSidebar,
          }}
        >
          <Sidebar routes={routes} display="none" {...props} />
          <Box
            float="right"
            minHeight="100vh"
            height="100%"
            overflow="auto"
            position="relative"
            maxHeight="100%"
            w={{ base: '100%', xl: 'calc( 100% - 290px )' }}
            maxWidth={{ base: '100%', xl: 'calc( 100% - 290px )' }}
            transition="all 0.33s cubic-bezier(0.685, 0.0473, 0.346, 1)"
            transitionDuration=".2s, .2s, .35s"
            transitionProperty="top, bottom, width"
            transitionTimingFunction="linear, linear, ease"
          >
            <Box>
              <Navbar
                onOpen={onOpen}
                brandText={getActiveRoute(routes)}
                secondary={getActiveNavbar(routes)}
                message={getActiveNavbarText(routes)}
                fixed={fixed}
                {...props}
              />
            </Box>

            {getRoute() ? (
              <Box
                mx="auto"
                p={{ base: '20px', md: '30px' }}
                pe="20px"
                minH="100vh"
                pt="50px"
              >
                <Routes>
                  {getRoute() ? (
                    <Box mx="auto" p={{ base: '20px', md: '30px' }} pe="20px" minH="100vh" pt="50px">
                      <Routes>
                        {getRoute()}
                        <Navigate to="/admin/default" />
                      </Routes>
                    </Box>
                  ) : null}
                </Routes>
              </Box>
            ) : null}
            <Box>{/* You are missing 'Footer' component here */}</Box>
          </Box>
        </SidebarContext.Provider>
      </Box>
    </Box>
  );
};

export default Dashboard;
