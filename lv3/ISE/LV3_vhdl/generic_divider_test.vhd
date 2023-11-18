library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity generic_divider_test is
	    Port ( clk_in : in  STD_LOGIC;
           clk_out : out  STD_LOGIC);
end generic_divider_test;

architecture Behavioral of generic_divider_test is

begin
	
	clk_2Hz	:	entity work.generic_divider generic map (25000000) port map (clk_in, clk_out);			--TO DO 1	-> instancirati generièki djelitelj frekvencije tako da se dobije signal frekvencije 2 Hz

end Behavioral;

