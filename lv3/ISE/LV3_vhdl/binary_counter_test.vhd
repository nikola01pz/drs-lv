library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity binary_counter_test is
    Port ( clk_in : in  STD_LOGIC;
           count_out : out  STD_LOGIC_VECTOR (1 downto 0));
end binary_counter_test;

architecture Behavioral of binary_counter_test is
	signal clk_1Hz	: std_logic;									-- TO DO 1 -> deklarirati signal clk_1Hz koji je tipa std_logic
begin

	divider_1Hz	:	entity work.generic_divider generic map (50000000) port map (clk_in, clk_1Hz);		--TO DO 2 -> instancirati generièki djelitelj frekvencije tako da ulazni signal takta pretvori u signal takta frekvencije 1Hz
	counter	:	entity work.binary_counter port map(clk_1Hz,count_out);							--TO DO 3 -> instancirati binarni brojaè tako da broji frekvencijom od 1Hz i da povratnu vrijednost spremi u signal count_temp

end Behavioral;


