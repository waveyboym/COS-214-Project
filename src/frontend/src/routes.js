import React from "react";
import { Icon } from "@chakra-ui/react";
import { MdHome } from "react-icons/md";
import MainDashboard from "./views/admin/default";

const routes = [
  {
    name: "Main Dashboard",
    layout: "/admin",
    path: "/default",
    icon: React.createElement(Icon, {
      as: MdHome,
      width: '20px',
      height: '20px',
      color: 'inherit',
    }),
    component: MainDashboard,
  },
];

export default routes;
