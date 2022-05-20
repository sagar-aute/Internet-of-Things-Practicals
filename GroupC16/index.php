<!DOCTYPE html>
<?php

        $op = $_GET['op'];

	    shell_exec("/usr/local/bin/gpio -g mode 6 out");	#FAN1
        shell_exec("/usr/local/bin/gpio -g mode 16 out");	#FAN2
		shell_exec("/usr/local/bin/gpio -g mode 21 out");	#Door Latch
        shell_exec("/usr/local/bin/gpio -g mode 22 out");	#Mains2 
        shell_exec("/usr/local/bin/gpio -g mode 23 out");	#Light1
		shell_exec("/usr/local/bin/gpio -g mode 24 out");	#Light2
        shell_exec("/usr/local/bin/gpio -g mode 25 out");	#Light3
		shell_exec("/usr/local/bin/gpio -g mode 5 out");	#FAN3
        shell_exec("/usr/local/bin/gpio -g mode 27 out");	#Mains1


        switch($op){
				case 1: shell_exec("/usr/local/bin/gpio -g write 21 0");#Door Latch OFF
                        break;
                case 2: shell_exec("/usr/local/bin/gpio -g write 21 1");#Door Latch ON
                        break;
                case 3: shell_exec("/usr/local/bin/gpio -g write 23 0");#Light 1
                        break;
                case 4: shell_exec("/usr/local/bin/gpio -g write 23 1");
                        break;
                case 5: shell_exec("/usr/local/bin/gpio -g write 6 0");#FAN1
                        break;
                case 6: shell_exec("/usr/local/bin/gpio -g write 6 1");
                        break;
                case 7: shell_exec("/usr/local/bin/gpio -g write 24 0");#Light2
                        break;
                case 8: shell_exec("/usr/local/bin/gpio -g write 24 1");
						break;
                case 9: shell_exec("/usr/local/bin/gpio -g write 16 0");#FAN2
                        break;
                case 10: shell_exec("/usr/local/bin/gpio -g write 16 1");
                        break;
                case 11: shell_exec("/usr/local/bin/gpio -g write 25 0");#Light3
                        break;
                case 12: shell_exec("/usr/local/bin/gpio -g write 25 1");
                        break;
                case 13: shell_exec("/usr/local/bin/gpio -g write 5 0");#FAN3
                        break;
                case 14: shell_exec("/usr/local/bin/gpio -g write 5 1");
                        break;
                case 15: shell_exec("/usr/local/bin/gpio -g write 27 0");#Mains1
                        break;
                case 16: shell_exec("/usr/local/bin/gpio -g write 27 1");
                        break;
				case 17: shell_exec("/usr/local/bin/gpio -g write 22 0");#Mains2
                        break;
                case 18: shell_exec("/usr/local/bin/gpio -g write 22 1");
                        break;
                
                default:shell_exec("/usr/local/bin/gpio -g write 21 0");
                        shell_exec("/usr/local/bin/gpio -g write 22 0");
                        shell_exec("/usr/local/bin/gpio -g write 23 0");
                        shell_exec("/usr/local/bin/gpio -g write 24 0");
						shell_exec("/usr/local/bin/gpio -g write 25 0");
						shell_exec("/usr/local/bin/gpio -g write 26 0");
                        shell_exec("/usr/local/bin/gpio -g write 27 0");
                        shell_exec("/usr/local/bin/gpio -g write 5 0");
						shell_exec("/usr/local/bin/gpio -g write 16 0");
						
        }
        include("page.html");
?>