library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE ieee.numeric_std.ALL;


entity practica1 is
	Port ( 
		a: in signed (3 downto 0);
		b: in signed (3 downto 0);
		c: in signed (3 downto 0);
		d: in signed (3 downto 0);
		e: in signed (3 downto 0);
		f: in signed (3 downto 0);
		g: in signed (3 downto 0);
		h: in signed (3 downto 0);
		sel1: in STD_LOGIC_VECTOR (1 downto 0);
		sel2: in STD_LOGIC_VECTOR (1 downto 0);

		res1: out signed (3 downto 0);
		res2: out signed (3 downto 0)
	);

end entity practica1;

architecture rtl of practica1 is
	signal temp1: signed (3 downto 0);
	signal temp2: signed (3 downto 0);
begin
	-- aquí va el código donde se asignan y seleccionan valores
	temp1 <= a when sel1 = "00" else
			 b when sel1 = "01" else
			 c when sel1 = "10" else
			 d; -- when sel1 = "11"
	
	with sel2 select temp2 <=
		e when "00",
		f when "01",
		g when "10",
		h when others; -- when "11"

	res1 <= temp1 + temp2;
	res2 <= temp2 - temp1;

end architecture rtl;