library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity moving_light is
	--TO DO 1 -> deklarirati ulaz "clk" (STD_LOGIC) i izlaz "output" (STD_LOGIC_VECTOR) velièine 8 bita
    Port (  clk: in std_logic;
				output: out std_logic_vector (7 downto 0)
		 );
end moving_light;

architecture Behavioral of moving_light is

	--TO DO 2 -> definirati korisnièki tip podataka naziva "state" koji može imati vrijednosti "state0", ... "state7"
	type state is (state0, state1, state2, state3, state4, state5, state6, state7);
	--TO DO 3 -> deklarirati signale "current_state" i "next_state" koji su tipa "state"
	signal current_state, next_state: state;
	--TO DO 4 -> deklarirati signal "clk_div" koji je tipa STD_LOGIC
	signal clk_div: std_logic;

begin

	--TO DO 5 -> instancirati generièki djelitelj frekvencije na naèin da od ulaznog singala takta kreira signal takta frekvencije 1 Hz
	divider_1Hz	:	entity work.generic_divider generic map (50000000) port map (clk, clk_div);
	
	----Lower section of FSM----
	process(clk_div)
	begin
		--TO DO 6 -> na rastuæi brid signala takta "clk_div" signalu "current_state" pridružiti vrijednost signala "next_state"
		if(clk_div'EVENT AND clk_div='1') then
			current_state <= next_state;
		end if;
	end process;
	
	----Upper section of FSM----
	process(current_state)
	begin
		case current_state is
			--TO DO 7 -> u ovisnosti o vrijednosti signala "current_state" signalima "output" i "next_state" pridružiti odgovarajuæe vrijednosti
			when state0 =>
				output <= "00000001";
				next_state <= state1;
			when state1 =>
				output <= "00000010";
				next_state <= state2;
			when state2 =>
				output <= "00000100";
				next_state <= state3;
			when state3 =>
				output <= "00001000";
				next_state <= state4;
			when state4 =>
				output <= "00010000";
				next_state <= state5;
			when state5 =>
				output <= "00100000";
				next_state <= state6;
			when state6 =>
				output <= "01000000";
				next_state <= state7;
			when state7 =>
				output <= "10000000";
				next_state <= state0;
		end case;
	end process;	

end Behavioral;

