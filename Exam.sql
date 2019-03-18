-- Question 1:
Insert into Navire(CODE_NAVIRE,NOM_NAVIRE)
values('BR087770','Le Turbulent')
GO
Insert into Campagne
Values(25,'TOCTOC',01/07/2019,null)
GO
Insert into AFFRETER
Values(25,'BR087770',01/07/2019,01/10/2019,null,null)
GO
-- Question 2 :
Update AFFRETER set port_arr = 'Marseille' 
where num_campagne = (select num_campagne from campagne where intitule_campagne = 'Novo' and datafin_campagne = 30/10/2014)
and code_navire = (select code_navire from navire where nom_navire = 'Restener')
GO
-- Question 3 :
Select z.nom_zone 
from zone_travail z
inner join parcourir p on p.code_zone = z.code_zone
order by nom_zone desc
GO

-- Question 4 :

select n.nom_navire
from navire n
inner join affreter a on a.code_navire = n.code_navire
inner join campagne c on c.num_campagne = a.num_campagne
where c.intitule_campagne = 'IRIS' and c.datedep_campagne 20/10/2002 = and c.datefin_campagne = 25/04/2003
GO
-- Question 5 : 
select distinct nom_navire
from navire
where code_navire not in (
Select n.code_navire
from navire n
inner join affreter a on a.code_navire = n.code_navire 
inner join campagne c on c.num_campagne = a.num_campagne
where YEAR(a.datefin_campagne) = 2015 and YEAR(a.datedep_campagne) = 2015
)

-- Question 6 : 

Select count(num_campagne)
from parcourir
group by code_zone

-- Question 7

Select p.code_organisme
from participer p
group by p.code_organisme
having count(p.num_campagne) > 3

-- Quesiton 8 

CREATE TABLE Personne
(num_pers numeric(10) not null, 
code_campagne varchar2(50) not null, 
prenom_pers varchar2(50) not null,
  nom_pers varchar2(50) not null,
    profession varchar2(50) ,
      grade varchar2(50) ,
        profil varchar2(50) l,
        CONSTRAINT pk_personne PRIMARY KEY (num_pers),
  CONSTRAINT fk_campagne
    FOREIGN KEY (code_campagne)
    REFERENCES campagne(code_campagne)
);
GO
Insert into Personne
Values('Novo','Ahmed','Al Saoud','Capitain','G1','P1')
GO
Insert into Personne
Values('Novo','Salah','Al Salah','Ingénieur','G2','P2')
GO
Insert into Personne
Values('Novo','Mohamed','Salah','Stagiaire','G1','P1')
GO
Insert into Personne
Values('Novo','Marc','Simon','Capitain','G2','P3')
GO









