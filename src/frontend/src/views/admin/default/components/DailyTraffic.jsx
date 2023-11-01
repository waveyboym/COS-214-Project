import React from "react";

// Chakra imports
import { Box, Flex, Icon, Text, useColorModeValue } from "@chakra-ui/react";
import BarChart from "../../../../components/charts/BarChart.jsx";

// Custom components
import Card from "../../../../components/card/Card.jsx";
import {
  barChartDataDailyTraffic,
  barChartOptionsDailyTraffic,
} from "../../../../variables/charts.jsx";

// Assets

export default function DailyTraffic(props) {
  const { ...rest } = props;

  // Chakra Color Mode
  const textColor = useColorModeValue("secondaryGray.900", "white");
  return (
    <Card align='center' direction='column' w='100%' {...rest}>
      <Flex justify='space-between' align='start' px='10px' pt='5px'>
        <Flex flexDirection='column' align='start' me='20px'>
          <Flex w='100%'>
            <Text
              me='auto'
              color='secondaryGray.600'
              fontSize='sm'
              fontWeight='500'>
              Most Popular Dish
            </Text>
          </Flex>
          <Flex align='end'>
            <Text
              color={textColor}
              fontSize='34px'
              fontWeight='700'
              lineHeight='100%'>
              19
            </Text>
            <Text
              ms='6px'
              color='secondaryGray.600'
              fontSize='sm'
              fontWeight='500'>
              Customers Today
            </Text>
          </Flex>
        </Flex>
      </Flex>
      <Box h='240px' mt='auto'>
        <BarChart
          chartData={barChartDataDailyTraffic}
          chartOptions={barChartOptionsDailyTraffic}
        />
      </Box>
    </Card>
  );
}
