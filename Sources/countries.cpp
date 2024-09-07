#include <CTRPluginFramework.hpp>
#include "cheats.hpp"

namespace CTRPluginFramework
{
	// Note: Adding the missing countries (below in green) results in a console freeze at game launch due to a faulty memory allocation.
    
	const std::vector<States> g_statesjapan =
	{
		{ "Not Set", 0 },
		{ "Tokyo", 2 },
		{ "Hokkaido", 3 },
		{ "Aomori", 4 },
		{ "Iwate", 5 },
		{ "Miyagi", 6 },
		{ "Akita", 7 },
		{ "Yamagata", 8 },
		{ "Fukushima", 9 },
		{ "Ibaraki", 0xA },
		{ "Tochigi", 0xB },
		{ "Gunma", 0xC },
		{ "Saitama", 0xD },
		{ "Chiba", 0xE },
		{ "Kanagawa", 0xF },
		{ "Toyama", 0x10 },
		{ "Ishikawa", 0x11 },
		{ "Fukui", 0x12 },
		{ "Yamanashi", 0x13 },
		{ "Nagano", 0x14 },
		{ "Niigata", 0x15 },
		{ "Gifu", 0x16 },
		{ "Shizuoka", 0x17 },
		{ "Aichi", 0x18 },
		{ "Mie", 0x19 },
		{ "Shiga", 0x1A },
		{ "Kyoto", 0x1B },
		{ "Osaka", 0x1C },
		{ "Hyogo", 0x1D },
		{ "Nara", 0x1E },
		{ "Wakayama", 0x1F },
		{ "Tottori", 0x20 },
		{ "Shimane", 0x21 },
		{ "Okayama", 0x22 },
		{ "Hiroshima", 0x23 },
		{ "Yamaguchi", 0x24 },
		{ "Tokushima", 0x25 },
		{ "Kagawa", 0x26 },
		{ "Ehime", 0x27 },
		{ "Kochi", 0x28 },
		{ "Fukuoka", 0x29 },
		{ "Saga", 0x2A },
		{ "Nagasaki", 0x2B },
		{ "Kumamoto", 0x2C },
		{ "Oita", 0x2D },
		{ "Miyazaki", 0x2E },
		{ "Kagoshima", 0x2F },
		{ "Okinawa", 0x30 }
	};

	const std::vector<States> g_statesanguilla =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesantigua =
	{
		{ "Not Set", 0 },
		{ "Saint John", 2 },
		{ "Barbuda", 3 },
		{ "Saint George", 4 },
		{ "Saint Mary", 5 },
		{ "Saint Paul", 6 },
		{ "Saint Peter", 7 },
		{ "Saint Philip", 8 }
	};
	
	const std::vector<States> g_statesargentina =
	{
		{ "Not Set", 0 },
		{ "Distrito Federal", 2 },
		{ "Buenos Aires", 3 },
		{ "Catamarca", 4 },
		{ "Chaco", 5 },
		{ "Chubut", 6 },
		{ "Córdoba", 7 },
		{ "Corrientes", 8 },
		{ "Entre Rios", 9 },
		{ "Formosa", 0xA },
		{ "Jujuy", 0xB },
		{ "La Pampa", 0xC },
		{ "La Rioja", 0xD },
		{ "Mendoza", 0xE },
		{ "Misiones", 0xF },
		{ "Neuquén", 0x10 },
		{ "Rio Negro", 0x11 },
		{ "Salta", 0x12 },
		{ "San Juan", 0x13 },
		{ "San Luis", 0x14 },
		{ "Santa Cruz", 0x15 },
		{ "Santa Fe", 0x16 },
		{ "Santiago Del Estero", 0x17 },
		{ "Tierra Del Fuego...", 0x18 },
		{ "Tucumán", 0x19 }
	};
	
	const std::vector<States> g_statesaruba =
	{
		{ "Not Set", 0 }		
	};
	
	const std::vector<States> g_statesbahamas =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesbarbados =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesbelize =
	{
		{ "Not Set", 0 },
		{ "Cayo", 2 },
		{ "Belize", 3 },
		{ "Corozal", 4 },
		{ "Orange Walk", 5 },
		{ "Stann Creek", 6 },
		{ "Toldeo", 7 }
	};
	
	const std::vector<States> g_statesbolivia =
	{
		{ "Not Set", 0 },
		{ "La Paz", 2 },
		{ "Chuquisaca", 3 },
		{ "Cochabamba", 4 },
		{ "El Beni", 5 },
		{ "Oruro", 6 },
		{ "Pando", 7 },
		{ "Potosí", 8 },
		{ "Santa Cruz", 9 },
		{ "Tarija", 0xA }		
	};
	
	const std::vector<States> g_statesbrazil =
	{
		{ "Not Set", 0 },
		{ "Distrito Federal", 2 },
		{ "Acre", 3 },
		{ "Alagoas", 4 },
		{ "Amapá", 5 },
		{ "Amazonas", 6 },
		{ "Bahia", 7 },
		{ "Ceará", 8 },
		{ "Espírito Santo", 9 },
		{ "Mato Grosso Do Sul", 0xA },
		{ "Maranhão", 0xB },
		{ "Mato Grosso", 0xC },
		{ "Minas Gerais", 0xD },
		{ "Pará", 0xE },
		{ "Paraíba", 0xF },
		{ "Paraná", 0x10 },
		{ "Piauí", 0x11 },
		{ "Rio De Janeiro", 0x12 },
		{ "Rio Grande Do Norte", 0x13 },
		{ "Rio Grande Do Sul", 0x14 },
		{ "Rondônia", 0x15 },
		{ "Roraima", 0x16 },
		{ "Santa Catarina", 0x17 },
		{ "São Paulo", 0x18 },
		{ "Sergipe", 0x19 },
		{ "Goiás", 0x1A },
		{ "Pernambuco", 0x1B },
		{ "Tocantins", 0x1C }
	};
	
	const std::vector<States> g_statesbritish =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statescanada =
	{
		{ "Not Set", 0 },
		{ "Ontario", 2 },
		{ "Alberta", 3 },
		{ "British Columbia", 4 },
		{ "Manitoba", 5 },
		{ "New Brunswick", 6 },
		{ "Newfoundland...", 7 },
		{ "Nova Scotia", 8 },
		{ "Prince Edward Island", 9 },
		{ "Quebec", 0xA },
		{ "Saskatchewan", 0xB },
		{ "Yukon", 0xC },
		{ "Northwest Territories", 0xD },
		{ "Nunavut", 0xE }
	};
	
	const std::vector<States> g_statescayman =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_stateschile =
	{
		{ "Not Set", 0 },
		{ "Región Metropolitana", 2 },
		{ "Valparaíso", 3 },
		{ "Aisén...", 4 },
		{ "Antogagasta", 5 },
		{ "Araucanía", 6 },
		{ "Atacam", 7 },
		{ "Bío-Bío", 8 },
		{ "Coquimbo", 9 },
		{ "Libertador...", 0xA },
		{ "Los Lagos", 0xB },
		{ "Magallanes y Antártica...", 0xC },
		{ "Maule", 0xD },
		{ "Tarapacá", 0xE }
	};
	
	const std::vector<States> g_statescolombia =
	{
		{ "Not Set", 0 },
		{ "Distrito Capital", 2 },
		{ "Cundinamarca", 3 },
		{ "Amazonas", 4 },
		{ "Antioquia", 5 },
		{ "Arauca", 6 },
		{ "Atlántico", 7 },
		{ "Bolívar", 8 },
		{ "Boyacá", 9 },
		{ "Caldas", 0xA },
		{ "Caquetá", 0xB },
		{ "Cauca", 0xC },
		{ "Cesar", 0xD },
		{ "Chocó", 0xE },
		{ "Córdoba", 0xF },
		{ "Guaviare", 0x10 },
		{ "Guainía", 0x11 },
		{ "Huila", 0x12 },
		{ "La Guajira", 0x13 },
		{ "Magdalena", 0x14 },
		{ "Meta", 0x15 },
		{ "Nariño", 0x16 },
		{ "Norte De Santander", 0x17 },
		{ "Putumayo", 0x18 },
		{ "Quindío", 0x19 },
		{ "Risaralda", 0x1A },
		{ "Archipiélago...", 0x1B },
		{ "Santander", 0x1C },
		{ "Sucre", 0x1D },
		{ "Tolima", 0x1E },
		{ "Valle Del Cauca", 0x1F },
		{ "Vaupés", 0x20 },
		{ "Vichada", 0x21 },
		{ "Casanare", 0x22 }
		
	};
	
	const std::vector<States> g_statescosta =
	{
		{ "Not Set", 0 },
		{ "San José", 2 },
		{ "Alajuela", 3 },
		{ "Cartago", 4 },
		{ "Guanacaste", 5 },
		{ "Heredia", 6 },
		{ "Limón", 7 },
		{ "Puntarenas", 8 }
	};
	
	const std::vector<States> g_statesdominica =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesdominican =
	{
		{ "Not Set", 0 },
		{ "Distrito Nacional", 2 },
		{ "Azua", 3 },
		{ "Baoruco", 4 },
		{ "Barahona", 5 },
		{ "Dajabón", 6 },
		{ "Duarte", 7 },
		{ "Espaillat", 8 },
		{ "Independencia", 9 },
		{ "La Altagracia", 0xA },
		{ "Elías Piña", 0xB },
		{ "La Romana", 0xC },
		{ "María Trinidad Sánchez", 0xD },
		{ "Monte Cristi", 0xE },
		{ "Pedernales", 0xF },
		{ "Peravia", 0x10 },
		{ "Puerto Plata", 0x11 },
		{ "Salcedo", 0x12 },
		{ "Samaná", 0x13 },
		{ "Sánchez Ramírez", 0x14 },
		{ "San Juan", 0x15 },
		{ "San Pedro De Macorís", 0x16 },
		{ "Santiago", 0x17 },
		{ "Santiago Rodríguez", 0x18 },
		{ "Valverde", 0x19 },
		{ "El Seíbo", 0x1A },
		{ "Hato Mayor", 0x1B },
		{ "La Vega", 0x1C },
		{ "Monseñor Nouel", 0x1D },
		{ "Monte Plata", 0x1E },
		{ "San Cristóbal", 0x1F }
	};
	
	const std::vector<States> g_statesecuador =
	{
		{ "Not Set", 0 },
		{ "Pichincha", 2 },
		{ "Galápagos", 3 },
		{ "Azuay", 4 },
		{ "Bolívar", 5 },
		{ "Cañar", 6 },
		{ "Carchi", 7 },
		{ "Chimborazo", 8 },
		{ "Cotopaxi", 9 },
		{ "El Oro", 0xA },
		{ "Esmerladas", 0xB },
		{ "Guayas", 0xC },
		{ "Imbabura", 0xD },
		{ "Loja", 0xE },
		{ "Los Ríos", 0xF },
		{ "Manabí", 0x10 },
		{ "Morona-Santiago", 0x11 },
		{ "Pastaza", 0x12 },
		{ "Tungurahua", 0x13 },
		{ "Zamora-Chinchipe", 0x14 },
		{ "Sucumbios", 0x15 },
		{ "Napo", 0x16 },
		{ "Orellana", 0x17 },
		{ "Santa Elena", 0x18 },
		{ "Santo Domingo...", 0x19 }
	};
	
	const std::vector<States> g_statesel =
	{
		{ "Not Set", 0 },
		{ "San Salvador", 2 },
		{ "Ahuachapán", 3 },
		{ "Cabañas", 4 },
		{ "Chalatenango", 5 },
		{ "Cuscatlán", 6 },
		{ "La Libertad", 7 },
		{ "La Paz", 8 },
		{ "La Unión", 9 },
		{ "Morazán", 0xA },
		{ "San Miguel", 0xB },
		{ "Santa Anna", 0xC },
		{ "San Vicente", 0xD },
		{ "Sonsonate", 0xE },
		{ "Usulután", 0xF }
	};
	
	const std::vector<States> g_statesfrench =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesgrenada =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesguadeloupe =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesguatemala =
	{
		{ "Not Set", 0 },
		{ "Guatemala", 2 },
		{ "Alta Verapaz", 3 },
		{ "Baja Verapaz", 4 },
		{ "Chimaltenango", 5 },
		{ "Chiquimula", 6 },
		{ "El Progreso", 7 },
		{ "Escuintla", 8 },
		{ "HueHuetenango", 9 },
		{ "Izabal", 0xA },
		{ "Jalapa", 0xB },
		{ "Jutiapa", 0xC },
		{ "Petén", 0xD },
		{ "Quetzaltenango", 0xE },
		{ "Quiché", 0xF },
		{ "Retalhuleu", 0x10 },
		{ "Sacatepéquez", 0x11 },
		{ "San Marcos", 0x12 },
		{ "Santa Rosa", 0x13 },
		{ "Sololá", 0x14 },
		{ "Suchitepéquez", 0x15 },
		{ "Totonicapán", 0x16 },
		{ "Zacapa", 0x17 }
	};
	
	const std::vector<States> g_statesguyana =
	{
		{ "Not Set", 0 },
		{ "Demerara-Mahaica", 2 },
		{ "Barima-Waini", 3 },
		{ "Cuyuni-Mazaruni", 4 },
		{ "East Berbice-Corentyne", 5 },
		{ "Essequibo Islands...", 6 },
		{ "Mahaica-Berbice", 7 },
		{ "Pomeroon-Supenaam", 8 },
		{ "Potaro-Siparuni", 9 },
		{ "Upper Demerara-Berbice", 0xA },
		{ "Upper Takutu...", 0xB }
	};
	
	const std::vector<States> g_stateshaiti =
	{
		{ "Not Set", 0 },
		{ "Ouest", 2 },
		{ "Nord-Ouest", 3 },
		{ "Artibonite", 4 },
		{ "Centre", 5 },
		{ "Grand'Anse", 6 },
		{ "Nord", 7 },
		{ "Nord-Est", 8 },
		{ "Sud", 9 },
		{ "Sud-Est", 0xA },
		{ "Nippes", 0xB }
	};
	
	const std::vector<States> g_stateshonduras =
	{
		{ "Not Set", 0 },
		{ "Francisco Morazán", 2 },
		{ "Atlántida", 3 },
		{ "Choluteca", 4 },
		{ "Colón", 5 },
		{ "Comayagua", 6 },
		{ "Copán", 7 },
		{ "Cortés", 8 },
		{ "El Paraíso", 9 },
		{ "Gracias A Dios", 0xA },
		{ "Intibucá", 0xB },
		{ "Islas De La Bahía", 0xC },
		{ "La Paz", 0xD },
		{ "Lempira", 0xE },
		{ "Ocotepeque", 0xF },
		{ "Olancho", 0x10 },
		{ "Santa Bárbara", 0x11 },
		{ "Valle", 0x12 },
		{ "Yoro", 0x13 }
		
	};
	
	const std::vector<States> g_statesjamaica =
	{
		{ "Not Set", 0 },
		{ "Saint Thomas", 2 },
		{ "Clarendon", 3 },
		{ "Hanover", 4 },
		{ "Manchester", 5 },
		{ "Portland", 6 },
		{ "Saint Andrew", 7 },
		{ "Saint Ann", 8 },
		{ "Saint Catherine", 9 },
		{ "Saint Elizabeth", 0xA },
		{ "Saint James", 0xB },
		{ "Saint Mary", 0xC },
		{ "Trelawny", 0xD },
		{ "Westmoreland", 0xE },
		{ "Kingston", 0xF }
	};
	
	const std::vector<States> g_statesmartinique =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesmexico =
	{
		{ "Not Set", 0 },
		{ "Distrito Federal", 2 },
		{ "Aguascalientes", 3 },
		{ "Baja California", 4 },
		{ "Baja California Sur", 5 },
		{ "Campeche", 6 },
		{ "Chiapas", 7 },
		{ "Chihuahua", 8 },
		{ "Coahuila De Zaragoza", 9 },
		{ "Colima", 0xA },
		{ "Durango", 0xB },
		{ "Guanajuato", 0xC },
		{ "Guerrero", 0xD },
		{ "Hidalgo", 0xE },
		{ "Jalisco", 0xF },
		{ "México", 0x10 },
		{ "Michoácan De Ocampo", 0x11 },
		{ "Morelos", 0x12 },
		{ "Nayarit", 0x13 },
		{ "Nuevo León", 0x14 },
		{ "Oaxaca", 0x15 },
		{ "Puebla", 0x16 },
		{ "Querétaro De Arteaga", 0x17 },
		{ "Quintana Roo", 0x18 },
		{ "San Luis Potosí", 0x19 },
		{ "Sinaloa", 0x1A },
		{ "Sonora", 0x1B },
		{ "Tabasco", 0x1C },
		{ "Tamaulipas", 0x1D },
		{ "Tlaxcala", 0x1E },
		{ "Veracruz-Llave", 0x1F },
		{ "Yucatán", 0x20 },
		{ "Zacatecas", 0x21 }
	};
	
	const std::vector<States> g_statesmontserrat =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesnetherlandsantilles =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesnicaragua =
	{
		{ "Not Set", 0 },
		{ "Managua", 2 },
		{ "Boaco", 3 },
		{ "Carazo", 4 },
		{ "Chinandega", 5 },
		{ "Chontales", 6 },
		{ "Estelí", 7 },
		{ "Granada", 8 },
		{ "Jinotega", 9 },
		{ "León", 0xA },
		{ "Madriz", 0xB },
		{ "Masaya", 0xC },
		{ "Matagalpa", 0xD },
		{ "Nueva Segovia", 0xE },
		{ "Río San Juan", 0xF },
		{ "Rivas", 0x10 },
		{ "Atlántico Norte", 0x11 },
		{ "Atlántico Sur", 0x12 }
	};
	
	const std::vector<States> g_statespanama =
	{
		{ "Not Set", 0 },
		{ "Panamá", 2 },
		{ "Bocas Del Toro", 3 },
		{ "Chiriquí", 4 },
		{ "Coclé", 5 },
		{ "Colón", 6 },
		{ "Darién", 7 },
		{ "Herrera", 8 },
		{ "Los Santos", 9 },
		{ "Kuna Yala", 0xA },
		{ "Veraguas", 0xB }
	};
	
	const std::vector<States> g_statesparaguay =
	{
		{ "Not Set", 0 },
		{ "Central", 2 },
		{ "Alto Paraná", 3 },
		{ "Amambay", 4 },
		{ "Caaguazú", 5 },
		{ "Caazapá", 6 },
		{ "Concepción", 7 },
		{ "Cordillera", 8 },
		{ "Guairá", 9 },
		{ "Itapúa", 0xA },
		{ "Misiones", 0xB },
		{ "Ñeembucú", 0xC },
		{ "Paraguarí", 0xD },
		{ "Presidente Hayes", 0xE },
		{ "San Pedro", 0xF },
		{ "Canindeyú", 0x10 },
		{ "Asunción", 0x11 },
		{ "Alto Paraguay", 0x12 },
		{ "Boquerón", 0x13 }
	};
	
	const std::vector<States> g_statesperu =
	{
		{ "Not Set", 0 },
		{ "Lima", 2 },
		{ "Amazonas", 3 },
		{ "Ancash", 4 },
		{ "Apurímac", 5 },
		{ "Arequipa", 6 },
		{ "Ayacucho", 7 },
		{ "Cajamarca", 8 },
		{ "Callao", 9 },
		{ "Cuzco", 0xA },
		{ "Huancavelica", 0xB },
		{ "Huánuco", 0xC },
		{ "Ica", 0xD },
		{ "Junín", 0xE },
		{ "La Libertad", 0xF },
		{ "Lambayeque", 0x10 },
		{ "Loreto", 0x11 },
		{ "Madre De Dios", 0x12 },
		{ "Moquegua", 0x13 },
		{ "Pasco", 0x14 },
		{ "Piura", 0x15 },
		{ "Puno", 0x16 },
		{ "San Martín", 0x17 },
		{ "Tacna", 0x18 },
		{ "Tumbes", 0x19 },
		{ "Ucayali", 0x1A }
	};
	
	const std::vector<States> g_statesstkitts =
	{
		{ "Not Set", 0 },
		{ "Saint George...", 2 },
		{ "Christ Church...", 3 },
		{ "Saint Anne Sandy...", 4 },
		{ "Saint George...", 5 },
		{ "Saint James Windward", 6 },
		{ "Saint John Capesterre", 7 },
		{ "Saint John Figtree", 8 },
		{ "Saint Mary Cayon", 9 },
		{ "Saint Paul...", 0xA },
		{ "Saint Paul...", 0xB },
		{ "Saint Peter...", 0xC },
		{ "Saint Thomas Lowland", 0xD },
		{ "Saint Thomas...", 0xE },
		{ "Trinity Palmetto...", 0xF }
	};
	
	const std::vector<States> g_statesstlucia =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesstvincent =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statessuriname =
	{
		{ "Not Set", 0 },
		{ "Paramaribo", 2 },
		{ "Brokopondo", 3 },
		{ "Commewijne", 4 },
		{ "Coronie", 5 },
		{ "Marowijne", 6 },
		{ "Nickerie", 7 },
		{ "Para", 8 },
		{ "Saramacca", 9 },
		{ "Sipaliwini", 0xA },
		{ "Wanica", 0xB }
	};
	
	const std::vector<States> g_statestrinidad =
	{
		{ "Not Set", 0 },
		{ "Port-Of-Spain", 2 },
		{ "Arima", 3 },
		{ "Caroni", 4 },
		{ "Mayaro", 5 },
		{ "Nariva", 6 },
		{ "Saint Andrew", 7 },
		{ "Saint David", 8 },
		{ "Saint George", 9 },
		{ "Saint Patrick", 0xA },
		{ "San Fernando", 0xB },
		{ "Tobago", 0xC },
		{ "Victoria", 0xD },
		{ "Point Fortin", 0xE }
	};
	
	const std::vector<States> g_statesturks =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesunitedstates =
	{
		{ "Not Set", 0 },
		{ "District Of Columbia", 2 },
		{ "Alaska", 3 },
		{ "Alabama", 4 },
		{ "Arkansas", 5 },
		{ "Arizona", 6 },
		{ "California", 7 },
		{ "Colorado", 8 },
		{ "Connecticut", 9 },
		{ "Delaware", 0xA },
		{ "Florida", 0xB },
		{ "Georgia", 0xC },
		{ "Hawaii", 0xD },
		{ "Iowa", 0xE },
		{ "Idaho", 0xF },
		{ "Illinois", 0x10 },
		{ "Indiana", 0x11 },
		{ "Kansas", 0x12 },
		{ "Kentucky", 0x13 },
		{ "Louisiana", 0x14 },
		{ "Massachusetts", 0x15 },
		{ "Maryland", 0x16 },
		{ "Maine", 0x17 },
		{ "Michigan", 0x18 },
		{ "Minnesota", 0x19 },
		{ "Missouri", 0x1A },
		{ "Mississippi", 0x1B },
		{ "Montana", 0x1C },
		{ "North Carolina", 0x1D },
		{ "North Dakota", 0x1E },
		{ "Nebraska", 0x1F },
		{ "New Hampshire", 0x20 },
		{ "New Jersey", 0x21 },
		{ "New Mexico", 0x22 },
		{ "Nevada", 0x23 },
		{ "New York", 0x24 },
		{ "Ohio", 0x25 },
		{ "Oklahoma", 0x26 },
		{ "Oregon", 0x27 },
		{ "Pennsylvania", 0x28 },
		{ "Rhode Island", 0x29 },
		{ "South Carolina", 0x2A },
		{ "South Dakota", 0x2B },
		{ "Tennessee", 0x2C },
		{ "Texas", 0x2D },
		{ "Utah", 0x2E },
		{ "Virginia", 0x2F },
		{ "Vermont", 0x30 },
		{ "Washington", 0x31 },
		{ "Wisconsin", 0x32 },
		{ "West Virginia", 0x33 },
		{ "Wyoming", 0x34 },
		{ "Puerto Rico", 0x35 }
	};
	
	const std::vector<States> g_statesuruguay =
	{
		{ "Not Set", 0 },
		{ "Montevideo", 2 },
		{ "Artigas", 3 },
		{ "Canelones", 4 },
		{ "Cerro Largo", 5 },
		{ "Colonia", 6 },
		{ "Durazno", 7 },
		{ "Flores", 8 },
		{ "Florida", 9 },
		{ "Lavalleja", 0xA },
		{ "Maldonado", 0xB },
		{ "Paysandú", 0xC },
		{ "Río Negro", 0xD },
		{ "Rivera", 0xE },
		{ "Rocha", 0xF },
		{ "Salto", 0x10 },
		{ "San José", 0x11 },
		{ "Soriano", 0x12 },
		{ "Tacuarembó", 0x13 },
		{ "Treinta Y Tres", 0x14 }
	};
	
	const std::vector<States> g_statesusvirgin =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesvenezuela =
	{
		{ "Not Set", 0 },
		{ "Distrito Federal", 2 },
		{ "Amazonas", 3 },
		{ "Anzoátegui", 4 },
		{ "Apure", 5 },
		{ "Aragua", 6 },
		{ "Barinas", 7 },
		{ "Bolívar", 8 },
		{ "Carabobo", 9 },
		{ "Cojedes", 0xA },
		{ "Delta Amacuro", 0xB },
		{ "Falcón", 0xC },
		{ "Guárico", 0xD },
		{ "Lara", 0xE },
		{ "Mérida", 0xF },
		{ "Miranda", 0x10 },
		{ "Monagas", 0x11 },
		{ "Nueva Esparta", 0x12 },
		{ "Portuguesa", 0x13 },
		{ "Sucre", 0x14 },
		{ "Táchira", 0x15 },
		{ "Trujillo", 0x16 },
		{ "Yaracuy", 0x17 },
		{ "Zulia", 0x18 },
		{ "Dependencias Federales", 0x19 },
		{ "Vargas", 0x1A }
	};
	
	const std::vector<States> g_statesalbania =
	{
		{ "Not Set", 0 },
		{ "Tirana", 2 },
		{ "Berat", 3 },
		{ "Didër", 4 },
		{ "Durrës", 5 },
		{ "Elbasan", 6 },
		{ "Fier", 7 },
		{ "Gjirokastër", 8 },
		{ "Korçë", 9 },
		{ "Kukës", 0xA },
		{ "Lezhë", 0xB },
		{ "Shkodër", 0xC },
		{ "Vlorë", 0xD }
	};
	
	const std::vector<States> g_statesaustralia =
	{
		{ "Not Set", 0 },
		{ "Australian Capital...", 2 },
		{ "New South Wales", 3 },
		{ "Northern Territory", 4 },
		{ "Queensland", 5 },
		{ "South Australia", 6 },
		{ "Tasmania", 7 },
		{ "Victoria", 8 },
		{ "Western Australia", 9 }
	};
	
	const std::vector<States> g_statesaustria =
	{
		{ "Not Set", 0 },
		{ "Vienna", 2 },
		{ "Burgenland", 3 },
		{ "Carinthia", 4 },
		{ "Lower Austria", 5 },
		{ "Upper Austria", 6 },
		{ "Salzburg", 7 },
		{ "Styria", 8 },
		{ "Tyrol", 9 },
		{ "Vorarlberg", 0xA }
	};
	
	const std::vector<States> g_statesbelgium =
	{
		{ "Not Set", 0 },
		{ "Brussels Region", 2 },
		{ "Flanders", 3 },
		{ "Wallonia", 4 }
	};
	
	const std::vector<States> g_statesbosnia =
	{
		{ "Not Set", 0 },
		{ "Federation Of...", 2 },
		{ "Republika Srpska", 3 },
		{ "Brčko District", 4 }
	};
	
	const std::vector<States> g_statesbotswana =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesbulgaria =
	{
		{ "Not Set", 0 },
		{ "Sofia City", 2 },
		{ "Sofia Province", 3 },
		{ "Blagoevgrad", 4 },
		{ "Pleven", 5 },
		{ "Vidin", 6 },
		{ "Varna", 7 },
		{ "Burgas", 8 },
		{ "Dobrich", 9 },
		{ "Gabrovo", 0xA },
		{ "Haskovo", 0xB },
		{ "Yambol", 0xC },
		{ "Kardzhali", 0xD },
		{ "Kyustendil", 0xE },
		{ "Lovech", 0xF },
		{ "Montana", 0x10 },
		{ "Pazardzhik", 0x11 },
		{ "Pernik", 0x12 },
		{ "Plovdiv", 0x13 },
		{ "Razgrad", 0x14 },
		{ "Ruse", 0x15 },
		{ "Silistra", 0x16 },
		{ "Sliven", 0x17 },
		{ "Smolyan", 0x18 },
		{ "Stara Zagora", 0x19 },
		{ "Shumen", 0x1A },
		{ "Targovishte", 0x1B },
		{ "Veliko Tarnovo", 0x1C },
		{ "Vrasta", 0x1D }
	};
	
	const std::vector<States> g_statescroatia =
	{
		{ "Not Set", 0 },
		{ "Zagreb", 6 },
		{ "Bjelovar...", 7 },
		{ "Brod-Posavina...", 8 },
		{ "Dubrovnik", 9 },
		{ "Istria County", 0xA },
		{ "Karlovac County", 0xB },
		{ "Koprivnica...", 0xC },
		{ "Krapina-Zagorje...", 0xD },
		{ "Lika-Senj County", 0xE },
		{ "Međimurje County", 0xF },
		{ "Osijek-Baranja...", 0x10 },
		{ "Požega-Slavonia...", 0x11 },
		{ "Primorje-Gorski...", 0x12 },
		{ "Sisak-Moslavina...", 0x13 },
		{ "Split-Dalmatia", 0x14 },
		{ "Šibenik-Knin...", 0x15 },
		{ "Varaždin County", 0x16 },
		{ "Virovitica...", 0x17 },
		{ "Vukovar-Syrmia", 0x18 },
		{ "Zadar County", 0x19 },
		{ "Zagreb County", 0x1A }
	};
	
	const std::vector<States> g_statescyprus =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesczech =
	{
		{ "Not Set", 0 },
		{ "Prague", 2 },
		{ "Central Bohemian...", 3 },
		{ "South Bohemian...", 4 },
		{ "Plzeñ Region", 5 },
		{ "Karlovy Vary...", 6 },
		{ "Ústí nad Labem...", 7 },
		{ "Liberec Region", 8 },
		{ "Hradec Králové...", 9 },
		{ "Pardubice Region", 0xA },
		{ "Olomouc Region", 0xB },
		{ "Moravian-Silesian...", 0xC },
		{ "South Moravian...", 0xD },
		{ "Zlin Region", 0xE },
		{ "Vysočina Region", 0xF }
	};
	
	const std::vector<States> g_statesdenmark =
	{
		{ "Not Set", 0 },
		{ "Greenland", 0x12 },
		{ "Capital Region...", 0x13 },
		{ "Central Denmark...", 0x14 },
		{ "North Denmark", 0x15 },
		{ "Region Zealand", 0x16 },
		{ "Region Of Southern...", 0x17 },
		{ "Faroe Islands", 0x18 }
	};
	
	const std::vector<States> g_statesestonia =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesfinland =
	{
		{ "Not Set", 0 },
		{ "Uusima / Nyland", 8 },
		{ "Lappi / Lapland", 9 },
		{ "Pohjois...", 0xA },
		{ "Kainuu", 0xB },
		{ "Pohjois-Karjala...", 0xC },
		{ "Pohjois-Savo...", 0xD },
		{ "Etelä-Savo", 0xE },
		{ "Etelä-Pohjanmaa...", 0xF },
		{ "Pohjanmaa", 0x10 },
		{ "Pirkanmaa...", 0x11 },
		{ "Satakunta...", 0x12 },
		{ "Keski-Suomi...", 0x13 },
		{ "Keski-Suomi...", 0x14 },
		{ "Varsinais-Suomi...", 0x15 },
		{ "Etelä-Karjala...", 0x16 },
		{ "Päijät-Häme...", 0x17 },
		{ "Kanta-Häme...", 0x18 },
		{ "Itä-Uusimaa...", 0x19 },
		{ "Kymenlaakso...", 0x1A },
		{ "Ahvenanmaa...", 0x1B }
	};
	
	const std::vector<States> g_statesfrance =
	{
		{ "Not Set", 0 },
		{ "Île-De-France", 2 },
		{ "Alsace", 3 },
		{ "Aquitaine :D", 4 },
		{ "Auvergne", 5 },
		{ "Lower Normandy", 6 },
		{ "Burgundy", 7 },
		{ "Brittany", 8 },
		{ "Centre", 9 },
		{ "Champagne-Ardenne", 0xA },
		{ "Corsica", 0xB },
		{ "Franche-Comté", 0xC },
		{ "Upper Normandy", 0xD },
		{ "Languedoc-Roussillon", 0xE },
		{ "Limousin", 0xF },
		{ "Lorraine", 0x10 },
		{ "Midi-Pyrénées", 0x11 },
		{ "Nord-Pas-De-Calais", 0x12 },
		{ "Pays De La Loire", 0x13 },
		{ "Picardy", 0x14 },
		{ "Poitou-Charentes", 0x15 },
		{ "Provence-Alpes...", 0x16 },
		{ "Rhône-Alpes", 0x17 },
		{ "Guadeloupe", 0x18 },
		{ "Martinique", 0x19 },
		{ "French Guiana", 0x1A },
		{ "Réunion", 0x1B }
	};
	
	const std::vector<States> g_statesgermany =
	{
		{ "Not Set", 0 },
		{ "Berlin", 2 },
		{ "Hesse", 3 },
		{ "Baden-Württemberg", 4 },
		{ "Bavaria", 5 },
		{ "Brandenburg", 6 },
		{ "Bremen", 7 },
		{ "Hamburg", 8 },
		{ "Mecklenburg...", 9 },
		{ "Lower Saxony", 0xA },
		{ "North Rhine", 0xB },
		{ "Rhineland-Palatinate", 0xC },
		{ "Saarland", 0xD },
		{ "Saxony", 0xE },
		{ "Saxony-Anhalt", 0xF },
		{ "Schleswig-Holstein", 0x10 },
		{ "Thunringia", 0x11 }
	};
	
	const std::vector<States> g_statesgreece =
	{
		{ "Not Set", 0 },
		{ "Attica", 2 },
		{ "Central Greece", 3 },
		{ "Central Macedonia", 4 },
		{ "Crete", 5 },
		{ "East Macedonia...", 6 },
		{ "Epirus", 7 },
		{ "Ionian Islands", 8 },
		{ "North Aegean", 9 },
		{ "Peloponnese", 0xA },
		{ "South Aegean", 0xB },
		{ "Thessaly", 0xC },
		{ "West Greece", 0xD },
		{ "West Macedonia", 0xE }
	};
	
	const std::vector<States> g_stateshungary =
	{
		{ "Not Set", 0 },
		{ "Budapest", 2 },
		{ "Bács-Kiskun County", 3 },
		{ "Baranya County", 4 },
		{ "Békés County", 5 },
		{ "Borsod-Abaúj...", 6 },
		{ "Csongrád County", 7 },
		{ "Fejér County", 8 },
		{ "Gyõr-Moson-Sopron...", 9 },
		{ "Hajdú-Bihar County", 0xA },
		{ "Heves County", 0xB },
		{ "Jász-Nagykun...", 0xC },
		{ "Komárom...", 0xD },
		{ "Nógrád County", 0xE },
		{ "Pest County", 0xF },
		{ "Somogy County", 0x10 },
		{ "Szabolcs...", 0x11 },
		{ "Tolna County", 0x12 },
		{ "Vas County", 0x13 },
		{ "Vesprém County", 0x14 },
		{ "Zala County", 0x15 }
	};
	
	const std::vector<States> g_statesiceland =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesireland =
	{
		{ "Not Set", 0 },
		{ "Dublin", 2 },
		{ "County Carlow", 0xA },
		{ "County Cavan", 0xB },
		{ "County Clare", 0xC },
		{ "County Cork", 0xD },
		{ "County Donegal", 0xE },
		{ "County Galway", 0xF },
		{ "County Perry", 0x10 },
		{ "County Kildare", 0x11 },
		{ "County Kilkenny", 0x12 },
		{ "County Laois", 0x13 },
		{ "County Leitrim", 0x14 },
		{ "County Limerick", 0x15 },
		{ "County Longford", 0x16 },
		{ "County Louth", 0x17 },
		{ "County Mayo", 0x18 },
		{ "County Meath", 0x19 },
		{ "County Monaghan", 0x1A },
		{ "County Offaly", 0x1B },
		{ "County Roscommon", 0x1C },
		{ "County Sligo", 0x1D },
		{ "County Tipperary", 0x1E },
		{ "County Waterford", 0x1F },
		{ "County Westmeath", 0x20 },
		{ "County Wexford", 0x21 },
		{ "County Wicklow", 0x22 }
	};
	
	const std::vector<States> g_statesitaly =
	{
		{ "Not Set", 0 },
		{ "Lazio", 2 },
		{ "Aosta Valley", 3 },
		{ "Piedmont", 4 },
		{ "Liguria", 5 },
		{ "Lombardy", 6 },
		{ "Trentino-Alto Adige", 7 },
		{ "Veneto", 8 },
		{ "Friuli Venezia Giulia", 9 },
		{ "Emilia-Romagna", 0xA },
		{ "Tuscany", 0xB },
		{ "Umbria", 0xC },
		{ "Marche", 0xD },
		{ "Abruzzo", 0xE },
		{ "Molise", 0xF },
		{ "Campania", 0x10 },
		{ "Apulia", 0x11 },
		{ "Basilicata", 0x12 },
		{ "Calabria", 0x13 },
		{ "Sicily", 0x14 },
		{ "Sardinia", 0x15 }
	};
	
	const std::vector<States> g_stateslatvia =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_stateslesotho =
	{
		{ "Not Set", 0 },
		{ "Maseru", 2 },
		{ "Berea", 3 },
		{ "Butha-Buthe", 4 },
		{ "Leribe", 5 },
		{ "Mafeteng", 6 },
		{ "Mohale's Hoek", 7 },
		{ "Mokhotlong", 8 },
		{ "Qacha's Nek", 9 },
		{ "Quthing", 0xA },
		{ "Thaba-Tseka", 0xB }
	};
	
	const std::vector<States> g_statesliechtenstein =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_stateslithuania =
	{
		{ "Not Set", 0 },
		{ "Vilnius", 2 },
		{ "Alytus", 3 },
		{ "Kaunas", 4 },
		{ "Klaipéda", 5 },
		{ "Marijampolé", 6 },
		{ "Panevėžys", 7 },
		{ "Šiauliai", 8 },
		{ "Taurage", 9 },
		{ "Telšiai", 0xA },
		{ "Utena", 0xB }
	};
	
	const std::vector<States> g_statesluxembourg =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesmacedonia =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesmalta =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesmontenegro =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesmozambique =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesnamibia =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesnetherlands =
	{
		{ "Not Set", 0 },
		{ "North Holland", 2 },
		{ "Drenthe", 3 },
		{ "Flevoland", 4 },
		{ "Friesland", 5 },
		{ "Gelderland", 6 },
		{ "Groningen", 7 },
		{ "Limburg", 8 },
		{ "North Brabant", 9 },
		{ "Overijssel", 0xA },
		{ "South Holland", 0xB },
		{ "Utrecht", 0xC },
		{ "Zeeland", 0xD }
	};
	
	const std::vector<States> g_statesnewzealand =
	{
		{ "Not Set", 0 },
		{ "Wellington", 2 },
		{ "Auckland", 3 },
		{ "Bay Of Plenty", 4 },
		{ "Canterbury", 5 },
		{ "Otago", 6 },
		{ "Hawke's Bay", 7 },
		{ "Manawatu-Wanganui", 8 },
		{ "Nelson", 9 },
		{ "Northland", 0xA }
	};
	
	const std::vector<States> g_statesnorway =
	{
		{ "Not Set", 0 },
		{ "Oslo", 7 },
		{ "Akershus", 8 },
		{ "Aust-Agder", 9 },
		{ "Buskerud", 0xA },
		{ "Finnmark", 0xB },
		{ "Hedmark", 0xC },
		{ "Hordaland", 0xD },
		{ "Møre Og Romsdal", 0xE },
		{ "Nordland", 0xF },
		{ "Nord-Trøndelag", 0x10 },
		{ "Oppland", 0x11 },
		{ "Rogaland", 0x12 },
		{ "Sogn Og Fjordane", 0x13 },
		{ "Sør-Trøndelag", 0x14 },
		{ "Telemark", 0x15 },
		{ "Troms", 0x16 },
		{ "Vest-Agder", 0x17 },
		{ "Vestfold", 0x18 },
		{ "Østfold", 0x19 },
		{ "Svalbard", 0x1A }
	};
	
	const std::vector<States> g_statespoland =
	{
		{ "Not Set", 0 },
		{ "Masovia", 2 },
		{ "Lower Silesia", 3 },
		{ "Kuyavian...", 4 },
		{ "Lodz", 5 },
		{ "Lublin", 6 },
		{ "Lubusz", 7 },
		{ "Lesser Poland", 8 },
		{ "Opole", 9 },
		{ "Subcarpathia", 0xA },
		{ "Podlachia", 0xB },
		{ "Pomerania", 0xC },
		{ "Silesia", 0xD },
		{ "Świętokrzyskie", 0xE },
		{ "Warmian-Masurian...", 0xF },
		{ "Greater Poland", 0x10 },
		{ "Western Pomerania", 0x11 }
	};
	
	const std::vector<States> g_statesportugal =
	{
		{ "Not Set", 0 },
		{ "Lisbon", 2 },
		{ "Madeira", 7 },
		{ "Azores", 8 },
		{ "Aveiro", 9 },
		{ "Beja", 0xA },
		{ "Braga", 0xB },
		{ "Bragança", 0xC },
		{ "Castelo Branco", 0xD },
		{ "Coimbra", 0xE },
		{ "Évora", 0xF },
		{ "Faro", 0x10 },
		{ "Guarda", 0x11 },
		{ "Leiria", 0x12 },
		{ "Portalegre", 0x13 },
		{ "Porto", 0x14 },
		{ "Santarém", 0x15 },
		{ "Setúbal", 0x16 },
		{ "Viana Do Castelo", 0x17 },
		{ "Vila Real", 0x18 },
		{ "Viseu", 0x19 }
	};
	
	const std::vector<States> g_statesromania =
	{
		{ "Not Set", 0 },
		{ "Bucharest", 2 },
		{ "Alba", 3 },
		{ "Arad", 4 },
		{ "Arges", 5 },
		{ "Bacau", 6 },
		{ "Bihor", 7 },
		{ "Bistrita-Nasaud", 8 },
		{ "Botosani", 9 },
		{ "Braila", 0xA },
		{ "Brasov", 0xB },
		{ "Buzau", 0xC },
		{ "Calarasi", 0xD },
		{ "Caras-Severin", 0xE },
		{ "Cluj", 0xF },
		{ "Constanta", 0x10 },
		{ "Covasna", 0x11 },
		{ "Dâmbovita", 0x12 },
		{ "Dolj", 0x13 },
		{ "Galati", 0x14 },
		{ "Giurgiu", 0x15 },
		{ "Gorj", 0x16 },
		{ "Harghita", 0x17 },
		{ "Hunedoara", 0x18 },
		{ "Ialomita", 0x19 },
		{ "Iasi", 0x1A },
		{ "Ilfov", 0x1B },
		{ "Maramures", 0x1C },
		{ "Mehedinti", 0x1D },
		{ "Mures", 0x1E },
		{ "Neamt", 0x1F },
		{ "Olt", 0x20 },
		{ "Prahova", 0x21 },
		{ "Salaj", 0x22 },
		{ "Satu Mare", 0x23 },
		{ "Sibiu", 0x24 },
		{ "Suceava", 0x25 },
		{ "Teleorman", 0x26 },
		{ "Timis", 0x27 },
		{ "Tulcea", 0x28 },
		{ "Vâlcea", 0x29 },
		{ "Vaslui", 0x2A },
		{ "Vrancea", 0x2B }
	};
	
	const std::vector<States> g_statesrussia =
	{
		{ "Not Set", 0 },
		{ "Moscow City", 9 },
		{ "Adygey", 0xA },
		{ "Gorno-Altay", 0xB },
		{ "Altay", 0xC },
		{ "Amur", 0xD },
		{ "Arkhangel'sk", 0xE },
		{ "Astrakhan'", 0xF },
		{ "Bashkortostan", 0x10 },
		{ "Belgorod", 0x11 },
		{ "Bryansk", 0x12 },
		{ "Buryat", 0x13 },
		{ "Chechnya", 0x14 },
		{ "Chelyabinsk", 0x15 },
		{ "Chukot", 0x16 },
		{ "Chuvash", 0x17 },
		{ "Dagestan", 0x18 },
		{ "Ingushetia", 0x19 },
		{ "Irkutsk", 0x1A },
		{ "Ivanovo", 0x1B },
		{ "Kabardin-Balkar", 0x1C },
		{ "Kaliningrad", 0x1D },
		{ "Kalmyk", 0x1E },
		{ "Kaluga", 0x1F },
		{ "Kamchatka", 0x20 },
		{ "Karachay-Cherkess", 0x21 },
		{ "Karelia", 0x22 },
		{ "Kemerovo", 0x23 },
		{ "Khabarovsk", 0x24 },
		{ "Khakassia", 0x25 },
		{ "Khanty-Mansiy", 0x26 },
		{ "Kirov", 0x27 },
		{ "Komi", 0x28 },
		{ "Kostroma", 0x29 },
		{ "Krasnodar", 0x2A },
		{ "Krasnoyarsk", 0x2B },
		{ "Kurgan", 0x2C },
		{ "Kursk", 0x2D },
		{ "Leningrad", 0x2E },
		{ "Lipetsk", 0x2F },
		{ "Magadan", 0x30 },
		{ "Mariy-El", 0x31 },
		{ "Mordovia", 0x32 },
		{ "Moscow", 0x33 },
		{ "Murmansk", 0x34 },
		{ "Nenets", 0x35 },
		{ "Nizhegorod", 0x36 },
		{ "Novgorod", 0x37 },
		{ "Novosibirsk", 0x38 },
		{ "Omsk", 0x39 },
		{ "Orenburg", 0x3A },
		{ "Orel", 0x3B },
		{ "Penza", 0x3C },
		{ "Perm'", 0x3D },
		{ "Primor'ye", 0x3E },
		{ "Pskov", 0x3F },
		{ "Rostov", 0x40 },
		{ "Ryazan'", 0x41 },
		{ "Sakha", 0x42 },
		{ "Sakhalin", 0x43 },
		{ "Samara", 0x44 },
		{ "St. Petersburg", 0x45 },
		{ "Saratov", 0x46 },
		{ "North Ossetia", 0x47 },
		{ "Smolensk", 0x48 },
		{ "Stavropol'", 0x49 },
		{ "Sverdlovsk", 0x4A },
		{ "Tambov", 0x4B },
		{ "Tatarstan", 0x4C },
		{ "Tomsk", 0x4D },
		{ "Tula", 0x4E },
		{ "Tver'", 0x4F },
		{ "Tyumen'", 0x50 },
		{ "Tuva", 0x51 },
		{ "Udmurt", 0x52 },
		{ "Ul'yanovsk", 0x53 },
		{ "Vladimir", 0x54 },
		{ "Volgograd", 0x55 },
		{ "Vologda", 0x56 },
		{ "Voronezh", 0x57 },
		{ "Yamal-Nenets", 0x58 },
		{ "Yaroslavl'", 0x59 },
		{ "Yevrey", 0x5A },
		{ "Zabaykal'ye", 0x5B }
	};
	
	const std::vector<States> g_statesserbia =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesslovakia =
	{
		{ "Not Set", 0 },
		{ "Bratislava", 2 },
		{ "Banská Bystrica", 3 },
		{ "Košice", 4 },
		{ "Nitra", 5 },
		{ "Prešov", 6 },
		{ "Trenčín", 7 },
		{ "Trnava", 8 },
		{ "Trnava", 9 }
	};
	
	const std::vector<States> g_statesslovenia =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statessouthafrica =
	{
		{ "Not Set", 0 },
		{ "Gauteng", 2 },
		{ "Western Cape", 3 },
		{ "Northern Cape", 4 },
		{ "Eastern Cape", 5 },
		{ "KwaZulu-Natal", 6 },
		{ "Free State", 7 },
		{ "North West", 8 },
		{ "Mpumalanga", 9 },
		{ "Limpopo", 0xA }
	};
	
	const std::vector<States> g_statesspain =
	{
		{ "Not Set", 0 },
		{ "Madrid", 2 },
		{ "Andalusia", 3 },
		{ "Aragon", 4 },
		{ "Principality...", 5 },
		{ "Balearic Islands", 6 },
		{ "Canary Islands", 7 },
		{ "Cantabria", 8 },
		{ "Castile-La Mancha", 9 },
		{ "Castilla Y León", 0xA },
		{ "Catalonia", 0xB },
		{ "Valencia", 0xC },
		{ "Extremadura", 0xD },
		{ "Galicia", 0xE },
		{ "Murcia", 0xF },
		{ "Navarre", 0x10 },
		{ "Basque Country", 0x11 },
		{ "La Rioja", 0x12 },
		{ "Ceuta", 0x13 },
		{ "Melilla", 0x14 }
	};
	
	const std::vector<States> g_statesswaziland =
	{
		{ "Not Set", 0 },
		{ "Hhohho", 2 },
		{ "Lubombo", 3 },
		{ "Manzini", 4 },
		{ "Shiselweni", 5 }
	};
	
	const std::vector<States> g_statessweden =
	{
		{ "Not Set", 0 },
		{ "Stockholm County", 2 },
		{ "Skåne County", 3 },
		{ "Västra...", 4 },
		{ "Östergötland...", 5 },
		{ "Södermanland...", 6 },
		{ "Värmland County", 7 },
		{ "Uppsala County", 8 },
		{ "Gävleborg County", 9 },
		{ "Västerbotten...", 0xA },
		{ "Norrbotten...", 0xB },
		{ "Gotland Island", 0xC },
		{ "Jämtland County", 0xD },
		{ "Dalarna County", 0xE },
		{ "Blekinge County", 0xF },
		{ "Örebro County", 0x10 },
		{ "Västernorrland...", 0x11 },
		{ "Jönköping...", 0x12 },
		{ "Kronoberg...", 0x13 },
		{ "Kalmar County", 0x14 },
		{ "Västmanland...", 0x15 },
		{ "Halland County", 0x16 }
	};
	
	const std::vector<States> g_statesswitzerland =
	{
		{ "Not Set", 0 },
		{ "Bern", 2 },
		{ "Aargau", 4 },
		{ "Basel-City", 5 },
		{ "Fribourg", 6 },
		{ "Geneva", 7 },
		{ "Glarus", 8 },
		{ "Graubünden", 9 },
		{ "Jura", 0xA },
		{ "Luzern", 0xB },
		{ "Neuchâtel", 0xC },
		{ "Obwalden", 0xD },
		{ "St. Gallen", 0xE },
		{ "Schaffhausen", 0xF },
		{ "Schwyz", 0x10 },
		{ "Solothurn", 0x11 },
		{ "Thurgau", 0x12 },
		{ "Ticino", 0x13 },
		{ "Uri", 0x14 },
		{ "Valais", 0x15 },
		{ "Vaud", 0x16 },
		{ "Zug", 0x17 },
		{ "Zurich", 0x18 },
		{ "Appenzell Outer...", 0x19 },
		{ "Appenzell Inner...", 0x1A },
		{ "Basel-Landschaft", 0x1B },
		{ "Nidwalden", 0x1C }
	};
	
	const std::vector<States> g_statesturkey =
	{
		{ "Not Set", 0 },
		{ "Ankara", 2 },
		{ "Istanbul", 3 },
		{ "Izmir", 4 },
		{ "Bursa", 5 },
		{ "Adana", 6 },
		{ "Gaziantep", 7 },
		{ "Konya", 8 },
		{ "Antalya", 9 },
		{ "Diyarbakir", 0xA },
		{ "Mersin", 0xB },
		{ "Kayseri", 0xC }
	};
	
	const std::vector<States> g_statesunitedkingdom =
	{
		{ "Not Set", 0 },
		{ "England", 2 },
		{ "Scotland", 4 },
		{ "Wales", 5 },
		{ "Northern Ireland", 6 }
	};
	
	const std::vector<States> g_stateszambia =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_stateszimbabwe =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesazerbaijan =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesmauritania =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesmali =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesniger =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_stateschad =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statessudan =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_stateseritrea =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesdjibouti =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statessomalia =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesandorra =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesgibraltar =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesguernsey =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesisleofman =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesjersey =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesmonaco =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statestaiwan =
	{
		{ "Not Set", 0 },
		{ "Taipei", 2 },
		{ "Kaohsiung City", 3 },
		{ "Keelung City", 4 },
		{ "Hsinchu City", 5 },
		{ "Taichung City", 6 },
		{ "Chiayi City", 7 },
		{ "Tainan City", 8 },
		{ "New Taipei City", 9 },
		{ "Taoyuan County", 0xA },
		{ "HsinChu County", 0xB },
		{ "Miaoli County", 0xC }
	};
	
	const std::vector<States> g_stateskorea =
	{
		{ "Not Set", 0 },
		{ "Seoul", 2 },
		{ "Busan", 3 },
		{ "Daegu", 4 },
		{ "Incheon", 5 },
		{ "Gwangju", 6 },
		{ "Daejeon", 7 },
		{ "Ulsan", 8 },
		{ "Gyeonggi", 9 },
		{ "Gangwon", 0xA },
		{ "Chungcheongbuk", 0xB },
		{ "Chungcheongnam", 0xC },
		{ "Jeollabuk", 0xD },
		{ "Jeollanam", 0xE },
		{ "Gyeongsangbuk", 0xF },
		{ "Gyeongsangnam", 0x10 },
		{ "Jeju", 0x11 }
	};
	
	const std::vector<States> g_stateshongkong =
	{
		{ "Not Set", 0 }
	};
	
	/*const std::vector<States> g_statesmacao =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesindonesia =
	{
		{ "Not Set", 0 }
	};*/
	
	const std::vector<States> g_statessingapore =
	{
		{ "Not Set", 0 }
	};
	
	/*const std::vector<States> g_statesthailand =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesphilippines =
	{
		{ "Not Set", 0 }
	};*/
	
	const std::vector<States> g_statesmalaysia =
	{
		{ "Not Set", 0 },
		{ "Kuala Lumpur", 2 },
		{ "Johor", 3 },
		{ "Kedah", 4 },
		{ "Kelantan", 5 },
		{ "Melaka", 6 },
		{ "Negeri Sembilan", 7 },
		{ "Pahang", 8 },
		{ "Perak", 9 },
		{ "Perlis", 0xA },
		{ "Penang", 0xB },
		{ "Sarawak", 0xC },
		{ "Selangor", 0xD },
		{ "Terengganu", 0xE },
		{ "Labuan", 0xF },
		{ "Sabah", 0x10 },
		{ "Putrajaya", 0x11 }
	};
	
	const std::vector<States> g_stateschina =
	{
		{ "Not Set", 0 },
		{ "Beijing", 2 },
		{ "Chongqing", 3 },
		{ "Shanghai", 4 },
		{ "Tianjin", 5 },
		{ "Anhui", 6 },
		{ "Fujian", 7 },
		{ "Gansu", 8 },
		{ "Guangdong", 9 },
		{ "Guizhou", 0xA },
		{ "Hainan", 0xB },
		{ "Hebei", 0xC },
		{ "Heilongjiang", 0xD },
		{ "Henan", 0xE },
		{ "Hubei", 0xF },
		{ "Húnán", 0x10 },
		{ "Jiangsu", 0x11 },
		{ "Jiangxi", 0x12 },
		{ "Jilin", 0x13 },
		{ "Liaoning", 0x14 },
		{ "Qinghai", 0x15 },
		{ "Shanxi", 0x16 },
		{ "Shandong", 0x17 },
		{ "Shanxi", 0x18 },
		{ "Sichuan", 0x19 },
		{ "Yunnan", 0x1A },
		{ "Zhejiang", 0x1B },
		{ "Guangxi-Zhuangzu", 0x1D },
		{ "Nei-Menggu", 0x1E },
		{ "Ningxia-Huizu", 0x1F },
		{ "Xinjiang...", 0x20 },
		{ "Xizang", 0x21 }
	};
	
	const std::vector<States> g_statesunitedarab =
	{
		{ "Not Set", 0 },
		{ "Abu Dhabi", 2 },
		{ "Ajman", 3 },
		{ "Ash Shariqah", 4 },
		{ "Ras Al-Khaimah", 5 },
		{ "Dubai", 6 },
		{ "Al Fujayrah", 7 },
		{ "Umm Al Qaywayn", 8 }
	};
	
	const std::vector<States> g_statesindia =
	{
		{ "Not Set", 0 },
		{ "Delhi", 2 },
		{ "Andaman...", 3 },
		{ "Andhra Pradesh", 4 },
		{ "Assam", 5 },
		{ "Chandigarh", 6 },
		{ "Dadra And Nagar...", 7 },
		{ "Gujarãt", 8 },
		{ "Haryãna", 9 },
		{ "Himachal Pradesh", 0xA },
		{ "Kerala", 0xC },
		{ "Lakshadweep", 0xD },
		{ "Mahãrãshtra", 0xE },
		{ "Manipur", 0xF },
		{ "Meghãlaya", 0x10 },
		{ "Karnãtaka", 0x11 },
		{ "Nãgãland", 0x12 },
		{ "Odisha", 0x13 },
		{ "Puducherry", 0x14 },
		{ "Punjab", 0x15 },
		{ "Räjasthãn", 0x16 },
		{ "Tamil Nadu", 0x17 },
		{ "Tripura", 0x18 },
		{ "West Bengal", 0x19 },
		{ "Sikkim", 0x1A },
		{ "Mizoram", 0x1C },
		{ "Daman And Diu", 0x1D },
		{ "Goa", 0x1E },
		{ "Bihãr", 0x1F },
		{ "Madhya Pradesh", 0x20 },
		{ "Uttar Pradesh", 0x21 },
		{ "Chhattisgarh", 0x22 },
		{ "Jharkhand", 0x23 },
		{ "Uttarakhand", 0x24 },
		{ "Other", 0x25 }
	};
	
	/*const std::vector<States> g_statesegypt =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesoman =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesqatar =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_stateskuwait =
	{
		{ "Not Set", 0 }
	};*/
	
	const std::vector<States> g_statessaudi =
	{
		{ "Not Set", 0 },
		{ "Ar Riyad", 2 },
		{ "Al Bahah", 3 },
		{ "Al Madinah", 4 },
		{ "Ash Sharqiyah", 5 },
		{ "Al Qasim", 6 },
		{ "'Asir", 7 },
		{ "Ha'il", 8 },
		{ "Makkah", 9 },
		{ "Al Hudud Ash...", 0xA },
		{ "Najran", 0xB },
		{ "Jizan", 0xC },
		{ "Tabuk", 0xD },
		{ "Al Jawf", 0xE }
	};
	
	/*const std::vector<States> g_statessyria =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesbahrain =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesjordan =
	{
		{ "Not Set", 0 }
	};*/
	
	const std::vector<States> g_statessan =
	{
		{ "Not Set", 0 }
	};
	
	const std::vector<States> g_statesvatican =
	{
		{ "Not Set", 0 }
	};
	
	/*const std::vector<States> g_statesbermuda =
	{
		{ "Not Set", 0 }
	};*/

	const std::vector<Countries> g_flags =
	{
		{ "Japan", 1, g_statesjapan },
		{ "Anguilla", 8, g_statesanguilla },
		{ "Antigua And Barbuda", 9, g_statesantigua },
		{ "Argentina", 0xA, g_statesargentina },
		{ "Aruba", 0xB, g_statesaruba },
		{ "Bahamas", 0xC, g_statesbahamas },
		{ "Barbados", 0xD, g_statesbarbados },
		{ "Belize", 0xE, g_statesbelize },
		{ "Bolivia", 0xF, g_statesbolivia },
		{ "Brazil", 0x10, g_statesbrazil },
		{ "British Virgin Islands", 0x11, g_statesbritish },
		{ "Canada", 0x12, g_statescanada },
		{ "Cayman Islands", 0x13, g_statescayman },
		{ "Chile", 0x14, g_stateschile },
		{ "Colombia", 0x15, g_statescolombia },
		{ "Costa Rica", 0x16, g_statescosta },
		{ "Dominica", 0x17, g_statesdominica },
		{ "Dominican Republic", 0x18, g_statesdominican },
		{ "Ecuador", 0x19, g_statesecuador },
		{ "El Salvador", 0x1A, g_statesel },
		{ "French Guiana", 0x1B, g_statesfrench },
		{ "Grenada", 0x1C, g_statesgrenada },
		{ "Guadeloupe", 0x1D, g_statesguadeloupe },
		{ "Guatemala", 0x1E, g_statesguatemala },
		{ "Guyana", 0x1F, g_statesguyana },
		{ "Haiti", 0x20, g_stateshaiti },
		{ "Honduras", 0x21, g_stateshonduras },
		{ "Jamaica", 0x22, g_statesjamaica },
		{ "Martinique", 0x23, g_statesmartinique },
		{ "Mexico", 0x24, g_statesmexico },
		{ "Montserrat", 0x25, g_statesmontserrat },
		{ "Netherlands Antilles", 0x26, g_statesnetherlandsantilles },
		{ "Nicaragua", 0x27, g_statesnicaragua },
		{ "Panama", 0x28, g_statespanama },
		{ "Paraguay", 0x29, g_statesparaguay },
		{ "Peru", 0x2A, g_statesperu },
		{ "St Kitts And Nevis", 0x2B, g_statesstkitts },
		{ "St Lucia", 0x2C, g_statesstlucia },
		{ "St Vincent...", 0x2D, g_statesstvincent },
		{ "Suriname", 0x2E, g_statessuriname },
		{ "Trinidad And Tobago", 0x2F, g_statestrinidad },
		{ "Turks And Caicos...", 0x30, g_statesturks },
		{ "United States", 0x31, g_statesunitedstates },
		{ "Uruguay", 0x32, g_statesuruguay },
		{ "US Virgin Islands", 0x33, g_statesusvirgin },
		{ "Venezuela", 0x34, g_statesvenezuela },
		{ "Albania", 0x40, g_statesalbania },
		{ "Australia", 0x41, g_statesaustralia },
		{ "Austria", 0x42, g_statesaustria },
		{ "Belgium", 0x43, g_statesbelgium },
		{ "Bosnia...", 0x44, g_statesbosnia },
		{ "Botswana", 0x45, g_statesbotswana },
		{ "Bulgaria", 0x46, g_statesbulgaria },
		{ "Croatia", 0x47, g_statescroatia },
		{ "Cyprus", 0x48, g_statescyprus },
		{ "Czech Republic", 0x49, g_statesczech },
		{ "Denmark", 0x4A, g_statesdenmark },
		{ "Estonia", 0x4B, g_statesestonia },
		{ "Finland", 0x4C, g_statesfinland },
		{ "France", 0x4D, g_statesfrance },
		{ "Germany", 0x4E, g_statesgermany },
		{ "Greece", 0x4F, g_statesgreece },
		{ "Hungary", 0x50, g_stateshungary },
		{ "Iceland", 0x51, g_statesiceland },
		{ "Ireland", 0x52, g_statesireland },
		{ "Italy", 0x53, g_statesitaly },
		{ "Latvia", 0x54, g_stateslatvia },
		{ "Lesotho", 0x55, g_stateslesotho },
		{ "Liechtenstein", 0x56, g_statesliechtenstein },
		{ "Lithuania", 0x57, g_stateslithuania },
		{ "Luxembourg", 0x58, g_statesluxembourg },
		{ "Macedonia", 0x59, g_statesmacedonia },
		{ "Malta", 0x5A, g_statesmalta },
		{ "Montenegro", 0x5B, g_statesmontenegro },
		{ "Mozambique", 0x5C, g_statesmozambique },
		{ "Namibia", 0x5D, g_statesnamibia },
		{ "Netherlands", 0x5E, g_statesnetherlands },
		{ "New Zealand", 0x5F, g_statesnewzealand },
		{ "Norway", 0x60, g_statesnorway },
		{ "Poland", 0x61, g_statespoland },
		{ "Portugal", 0x62, g_statesportugal },
		{ "Romania", 0x63, g_statesromania },
		{ "Russia", 0x64, g_statesrussia },
		{ "Serbia", 0x65, g_statesserbia },
		{ "Slovakia", 0x66, g_statesslovakia },
		{ "Slovenia", 0x67, g_statesslovenia },
		{ "South Africa", 0x68, g_statessouthafrica },
		{ "Spain", 0x69, g_statesspain },
		{ "Swaziland", 0x6A, g_statesswaziland },
		{ "Sweden", 0x6B, g_statessweden },
		{ "Switzerland", 0x6C, g_statesswitzerland },
		{ "Turkey", 0x6D, g_statesturkey },
		{ "United Kingdom", 0x6E, g_statesunitedkingdom },
		{ "Zambia", 0x6F, g_stateszambia },
		{ "Zimbabwe", 0x70, g_stateszimbabwe },
		{ "Azerbaijan", 0x71, g_statesazerbaijan },
		{ "Mauritania", 0x72, g_statesmauritania },
		{ "Mali", 0x73, g_statesmali },
		{ "Niger", 0x74, g_statesniger },
		{ "Chad", 0x75, g_stateschad },
		{ "Sudan", 0x76, g_statessudan },
		{ "Eritrea", 0x77, g_stateseritrea },
		{ "Djibouti", 0x78, g_statesdjibouti },
		{ "Somalia", 0x79, g_statessomalia },
		{ "Andorra", 0x7A, g_statesandorra },
		{ "Gibraltar", 0x7B, g_statesgibraltar },
		{ "Guernsey", 0x7C, g_statesguernsey },
		{ "Isle Of Man", 0x7D, g_statesisleofman },
		{ "Jersey", 0x7E, g_statesjersey },
		{ "Monaco", 0x7F, g_statesmonaco },
		{ "Taiwan", 0x80, g_statestaiwan },
		{ "South Korea", 0x88, g_stateskorea },
		{ "Hong-Kong", 0x90, g_stateshongkong },
		//{ "Macao (!)", 0x91, g_statesmacao },
		//{ "Indonesia (!)", 0x98, g_statesindonesia },
		{ "Singapore", 0x99, g_statessingapore },
		//{ "Thailand (!)", 0x9A, g_statesthailand },
		//{ "Philippines (!)", 0x9B, g_statesphilippines },
		{ "Malaysia", 0x9C, g_statesmalaysia },
		{ "China", 0xA0, g_stateschina },
		{ "United Arab Emirates", 0xA8, g_statesunitedarab },
		{ "India", 0xA9, g_statesindia },
		//{ "Egypt (!)", 0xAA, g_statesegypt },
		//{ "Oman (!)", 0xAB, g_statesoman },
		//{ "Qatar (!)", 0xAC, g_statesqatar },
		//{ "Kuwait (!)", 0xAD, g_stateskuwait },
		{ "Saudi Arabia", 0xAE, g_statessaudi },
		//{ "Syria (!)", 0xAF, g_statessyria },
		//{ "Bahrain (!)", 0xB0, g_statesbahrain },
		//{ "Jordan (!)", 0xB1, g_statesjordan },
		{ "San Marino", 0xB8, g_statessan },
		{ "Vatican City", 0xB9, g_statesvatican },
		//{ "Bermuda", 0xBA, g_statesbermuda }
	};
}