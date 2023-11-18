library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity mux is
	port( input: in std_logic_vector (15 downto 0);
			num_sel: in std_logic_vector (1 downto 0);
			output: out std_logic_vector (3 downto 0)
	);
end mux;

architecture Behavioral of mux is

begin
	process(num_sel)
	begin
		case num_sel is
			when "00" => output <= input(15 downto 12);
			when "01" => output <= input(11 downto 8);
			when "10" => output <= input(7 downto 4);
			when others => output <= input(3 downto 0);
		end case;
	end process;
		
end Behavioral;

