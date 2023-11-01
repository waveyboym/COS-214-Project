import React from "react";

import { Icon } from "@chakra-ui/react";
import {
  MdHome,
} from "react-icons/md";

// Admin Imports
import DashboardContainer from "./pages/DashboardContainer";


const routes = [
  {
    name: "Main Dashboard",
    layout: "/admin",
    path: "/admin",
    component: DashboardContainer,
  },
];

export default routes;
