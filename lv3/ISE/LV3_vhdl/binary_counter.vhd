library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity binary_counter is
    Port ( clk_in : in  STD_LOGIC;
           count_out : out  STD_LOGIC_VECTOR (1 downto 0));
end binary_counter;

architecture Behavioral of binary_counter is
	signal count_temp: std_logic_vector (1 downto 0);																--TO DO 1 -> deklarirati signal count_temp koji je tipa std_logic i velièine je 2 bita
begin

	PROCESS(clk_in)
	
	BEGIN
		IF(clk_in'EVENT AND clk_in='1') THEN														--TO DO 2 -> detektirati rastuæi brid signala takta clk_in
			count_temp <= count_temp+1;															--TO DO 3 -> uveæati signal count_temp za 1
		END IF;
	END PROCESS;
	
	count_out <= count_temp;
																		--TO DO 4 -> izlaznom signalu count_out pridružiti vrijednost signala count_temp

end Behavioral;

