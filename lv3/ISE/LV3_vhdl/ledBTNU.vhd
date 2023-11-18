library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ledBTNU is
	port(
		switches: in std_logic_vector (7 downto 0);
		btn: in std_logic;
		leds: out std_logic_vector (7 downto 0)
	);
end ledBTNU;

architecture Behavioral of ledBTNU is
	signal output: std_logic_vector (15 downto 0);
	signal selectSW: std_logic_vector (3 downto 0);
	signal value: std_logic_vector (3 downto 0);
begin
	selectSW <= switches (7 downto 4);
	value <= switches (3 downto 0);
	process(btn)
	begin
		if(btn='1') then
				case selectSW is
					when "0001" => output(15 downto 12) <= value;
					when "0010" => output(11 downto 8) <= value;
					when "0100" => output(7 downto 4) <= value;
					when "1000" => output(3 downto 0) <= value;
					when others => output <= output;
				end case;  
		end if;	
	end process;
	leds <= switches;
	
end Behavioral;

