library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity traffic_light_CNTRL is
	--TO DO 1 -> deklarirati ulaz "clk" (STD_LOGIC) i izlaze "segment" i "display" (STD_LOGIC_VECTOR) velièine 8 i 4 bita
    Port (  clk: in std_logic;
				segment: out std_logic_vector (7 downto 0);
				display: out std_logic_vector (3 downto 0)
		  );
end traffic_light_CNTRL;

architecture Behavioral of traffic_light_CNTRL is

	--TO DO 2 -> definirati konstante "timeR", "timeRY", "timeG", "timeY" i "timeMAX" tipa integer te im pridružiti odgovarajuæe vrijednosti
	constant timeR: integer := 5;
	constant timeRY: integer := 1;
	constant timeG: integer := 4;
	constant timeY: integer := 2;
	constant timeMAX: integer := 5;
	
	--TO DO 3 -> definirati korisnièki tip podataka naziva "state" koji može imati vrijednosti "R", "RY", "G" i "Y"
	type state is (R,RY,G,Y);
	--TO DO 4 -> deklarirati signale "current_state" i "next_state" koji su tipa "state"
	signal current_state, next_state: state;
		--TO DO 5 -> deklarirati signal "clk_div" koji je tipa STD_LOGIC
	signal clk_div: std_logic;
	--TO DO 6 -> deklarirati signal "time_temp" koji je tipa integer i ima može poprimiti vrijednosti u rasponu od 0 do "timeMAX"
	signal time_temp: integer range 0 to timeMAX; 

begin

	--TO DO 7 -> signalu "display" pridružiti vrijednost tako da se svjetla semafora prikazuju na pokazniku AN0
	display <= "1110";
	--TO DO 8 -> instancirati generièki djelitelj frekvencije na naèin da od ulaznog singala takta kreira signal takta frekvencije 1 Hz
	divider_1Hz	:	entity work.generic_divider generic map (50000000) port map (clk, clk_div);
	
	----Lower section of FSM----
	process(clk_div)
		--TO DO 9 -> deklarirati varijablu "counter" koja može poprimiti vrijednosti u intervalu 0 do "timeMAX"
		variable counter: integer range 0 to timeMAX;
	begin
		--TO DO 10 -> na rastuæi brid signala takta "clk_div" poveæati varijablu "counter" za 1
		if(clk_div'EVENT AND clk_div='1') then		
			counter := counter+1;			
		--TO DO 11 -> ako varijabla "counter" ima vrijednost "time_temp" onda signalu "current_state" pridružiti vrijednost signala "next_state", a varijablu "counter" resetirati na 0
			if (counter=time_temp) then
				current_state <= next_state;
				counter := 0;
			end if;
		end if;
	end process;
	
	----Upper section of FSM----
	process(current_state)
	begin
		case current_state is
		--TO DO 12 -> u ovisnosti o vrijednosti signala "current_state" signalima "segment", "time_temp" i "next_state" pridružiti odgovarajuæe vrijednosti
			when R =>
				segment <= "01111111";
				time_temp <= timeR;
				next_state <= RY;
			when RY =>
				segment <= "01111101";
				time_temp <= timeRY;
				next_state <= G;
			when G =>
				segment <= "11101111";
				time_temp <= timeG;
				next_state <= Y;
			when Y =>
				segment <= "11111101";
				time_temp <= timeY;
				next_state <= R;
		end case;
	end process;

end Behavioral;

