library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity hex_decoder_test is
    Port ( number_in : in  STD_LOGIC_VECTOR(3 DOWNTO 0);
           segment_out : out  STD_LOGIC_VECTOR (7 downto 0);
           display_out : out  STD_LOGIC_VECTOR (3 downto 0)
			  );
end hex_decoder_test;

architecture Behavioral of hex_decoder_test is

begin

	--TO DO 1 -> instancirati hex_decoder tako na naèin da pretvori ulazni signal number_in u oblik prikladan za prikaz na 7 segmentnom pokazniku
	decoder	:	entity work.hex_decoder port map(number_in, segment_out);

	--TO DO 2 -> izlazu display_out pridružiti vrijednos tako da budu upaljeni pokaznici AN0 i AN2
	display_out <= "1010";

end Behavioral;

