library ieee;
use ieee.std_logic_1164.all;


entity smarthome is
port(
	clock: in std_logic;
	bsSwitch : in std_logic;
	blueORsensors : out std_logic;
	buzzerOUT : out std_logic;
	buzzerIN : in std_logic;
	ledlightsOUT : out std_logic;
	ledlightsIN : in std_logic;
	lightsensorIN : in std_logic;
	pwm : out std_logic;
	irsensorIN : in std_logic;
	test : out std_logic;
	doorIN : in std_logic
);
		end smarthome;
		
architecture a1 of smarthome is
signal opendoor,closedoor : std_logic;
begin

blueORsensors <= bsSwitch ;

 ledlightsOUT <= '1' when (bsSwitch = '1' AND lightsensorIN='0') else
					'1' when (bsSwitch='0' AND ledlightsIN='1') else '0';
					
test <= '1' when (bsSwitch = '1' AND irsensorIN='1') else
					'1' when (bsSwitch='0' AND doorIN='0') else '0';



process(clock)
 variable i : integer := 0;
 variable k : integer := 0;
 variable m : integer := 0;
 
begin
if clock'event and clock = '1' then
if buzzerIN='0' then
if i <= 35000 then i := i + 1 ; buzzerOUT <= '1';
elsif i > 35000 and i < 70000 then i := i + 1 ; buzzerOUT <= '0' ;
elsif i = 70000 then i := 0;
end if;
end if;

if (bsSwitch = '1' AND irsensorIN='1') or (bsSwitch='0' AND doorIN='0') then
if k <= 115000 then k := k + 1 ; pwm <= '1';
elsif k > 115000 and k < 500000 then k := k + 1 ; pwm <= '0' ;
elsif k = 500000 then k := 0;
end if;

else
if m <= 60000 then m := m + 1 ; pwm <= '1';
elsif m > 60000 and m < 500000 then m := m + 1 ; pwm <= '0' ;
elsif m = 500000 then m := 0; 
end if;

end if;
end if;
end process;

end a1;
