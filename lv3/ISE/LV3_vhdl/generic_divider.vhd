library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity generic_divider is
GENERIC
(
	N	:	INTEGER	:=	50_000_000
);
PORT
(
	clk_in	:	IN	STD_LOGIC;
	clk_out	:	OUT STD_LOGIC
);
end generic_divider;

architecture Behavioral of generic_divider is
	signal clk_t	:	STD_LOGIC;
begin

PROCESS(clk_in)
	variable temp	:	INTEGER RANGE 0 TO N;
BEGIN
	
	IF(clk_in'EVENT AND clk_in='1') THEN 								--TO DO 1 	-> detektirati rastuæi brid signala takta clk_in
		temp := temp+1;									--TO DO 2 	-> varijablu temp uveæati za 1
		IF(temp >= N) THEN
			clk_t <= not clk_t;								--TO DO 3	-> invertirati signal clk_t
			temp := 0;
		END IF;
	END IF;
	
END PROCESS;

	clk_out <= clk_t;							--TO DO 4	->	izlaznom signalu clk_out pridružiti vrijednost signala clk_t

end Behavioral;

