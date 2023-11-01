import React from "react";

// Chakra imports
import { Flex } from "@chakra-ui/react";

// Custom components
import { HSeparator } from "../../separator/Separator";

export function SidebarBrand() {
  //   Chakra color mode

  return (
    <Flex align='center' direction='column'>
       {/* go back to home page */}
       <a href='/index.html'>Everest Homepage</a>
      <HSeparator mb='20px' />
    </Flex>
  );
}

export default SidebarBrand;
