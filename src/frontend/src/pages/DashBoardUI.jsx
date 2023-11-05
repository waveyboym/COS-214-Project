/*!
  _   _  ___  ____  ___ ________  _   _   _   _ ___   
 | | | |/ _ \|  _ \|_ _|__  / _ \| \ | | | | | |_ _| 
 | |_| | | | | |_) || |  / / | | |  \| | | | | || | 
 |  _  | |_| |  _ < | | / /| |_| | |\  | | |_| || |
 |_| |_|\___/|_| \_\___/____\___/|_| \_|  \___/|___|
                                                                                                                                                                                                                                                                                                                                       
=========================================================
* Horizon UI - v1.1.0
=========================================================

* Product Page: https://www.horizon-ui.com/
* Copyright 2023 Horizon UI (https://www.horizon-ui.com/)

* Designed and Coded by Simmmple

=========================================================

* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

*/

// Chakra imports
import {
    Box,
    Icon,
    SimpleGrid,
    useColorModeValue,
  } from "@chakra-ui/react";
  import MiniStatistics from "../components/card/MiniStatistics";
  import IconBox from "../components/icons/IconBox";
  import React from "react";
  import {
    MdOutlineVerified,
    MdAssignmentInd,
    MdDiversity3
  } from "react-icons/md";
  import ComplexTable from "../views/admin/default/components/ComplexTable";
  import {
    columnsDataComplex,
  } from "../views/admin/default/variables/columnsData";
  import { useSocket } from '../contexts';
  import { useApiKeyStore, } from '../stateStore';
  import { useEffect, useState } from "react";

  //only for debug
  const expectedRes = JSON.parse("{\"status\":\"success\",\"player\":\"manager\",\"command\":\"get_all\",\"message\":{\"customer_count\":0,\"waiter_count\":0,\"rating\":0},\"table_data\":[]}");
  
  export default function DashBoardUI() {
    // Chakra Color Mode
    const brandColor = useColorModeValue("brand.500", "white");
    const boxBg = useColorModeValue("secondaryGray.300", "whiteAlpha.100");
    const socket = useSocket();
    const { apikey } = useApiKeyStore((state) => { return { apikey: state.apikey }; });
    const [allData, setAllData] = useState(expectedRes.message);
    const [tableData, setTableData] = useState(expectedRes.table_data);
    const [tableType, settableType] = useState("waiters");

    socket.onmessage = function(event){
      //the backend responds with the needed data
      const json = JSON.parse(event.data);
      
      //navigate to the tracking - page here
      if(json.status === "success" && json.player === "manager" && json.command === "get_all"){
        setAllData(json.message);
        setTableData(json.table_data);
      }
      else if(json.status === "success" && json.player === "manager" && json.command === "update_table"){
        setTableData(json.table_data);
      }
      else{
        console.log(json);
      }
    }

    const changeComplexTable = function(setTo){
      settableType(setTo);
      const json = { token: apikey, player: "manager", command: "update_table", message: setTo};
      socket.send(JSON.stringify(json));
    }

    useEffect(() => {
      const loadData = function(){
        const json = { token: apikey, player: "manager", command: "get_all", table_type: tableType};
        socket.send(JSON.stringify(json));
      }
    
      loadData();
    }, [])
    

    return (
      <Box pt={{ base: "130px" }}>
        <SimpleGrid
          columns={{ base: 1, md: 2, lg: 3, "2xl": 6 }}
          gap='20px'
          mb='20px'>
          <MiniStatistics
            startContent={
              <IconBox
                w='56px'
                h='56px'
                bg={boxBg}
                icon={
                  <Icon w='32px' h='32px' as={MdDiversity3} color={brandColor} />
                }
              />
            }
            name='Customers in restaurant'
            value={allData.customer_count}
          />
          <MiniStatistics
            startContent={
              <IconBox
                w='56px'
                h='56px'
                bg={boxBg}
                icon={<Icon w='28px' h='28px' as={MdAssignmentInd} color='white' />}
              />
            }
            name='Waiters in restaurant'
            value={allData.waiter_count}
          />
          <MiniStatistics
            startContent={
              <IconBox
                w='56px'
                h='56px'
                bg='linear-gradient(90deg, #4481EB 0%, #04BEFE 100%)'
                icon={
                  <Icon w='32px' h='32px' as={MdOutlineVerified} color={brandColor} />
                }
              />
            }
            name='Restaurant rating'
            value={allData.rating}
          />
        </SimpleGrid>
        <SimpleGrid  mb='20px'>
          <ComplexTable
            columnsData={columnsDataComplex}
            tableData={tableData}
            changeComplexTable={changeComplexTable}
          />
        </SimpleGrid>
      </Box>
    );
  }
  