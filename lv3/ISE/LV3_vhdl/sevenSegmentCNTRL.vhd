library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity sevenSegmentCNTRL is
	port( input: in std_logic_vector (7 downto 0);	
			clk: in std_logic;
			display: out std_logic_vector (3 downto 0);
			segment: out std_logic_vector (7 downto 0)
	);
end sevenSegmentCNTRL;

architecture Behavioral of sevenSegmentCNTRL is
	signal clk_div: std_logic;
	signal num_sel: std_logic_vector (1 downto 0);
	signal current_number: std_logic_vector (3 downto 0);
	signal input16: std_logic_vector (15 downto 0);
begin
	input16 <= "11101101"&input;
	clk_divider : entity work.generic_divider generic map (125000) port map (clk, clk_div);
	bin_counter : entity work.binary_counter port map (clk_div, num_sel);
	mux1: entity work.mux port map (input16, num_sel, current_number);
	mux2: entity work.mux port map ("1110110110110111", num_sel, display);
	decoder: entity work.hex_decoder port map (current_number, segment);
	
end Behavioral;

