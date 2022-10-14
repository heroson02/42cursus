<?php

define( 'DB_NAME', getenv('DATABASE') );

/** Database username */
define( 'DB_USER', getenv('NAME') );

/** Database password */
define( 'DB_PASSWORD', getenv('PWD') );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

define( 'WP_ALLOW_REPAIR', true );

define('AUTH_KEY',         'HKdHY4>7 E.eEpu0$@fy#kj<X*H9h)@xg+ck~|`:({u}k||Ko&-=ar/b#NH/F+?-');
define('SECURE_AUTH_KEY',  'rEBOT^ K1Y8mguv,]{,|T^BDQ4-z{XlQ?C(ub,T-?186*L%^/|-5yd):]88Ffbk}');
define('LOGGED_IN_KEY',    ')RZT;!,A42@vW#jNs+:I>+F }R,Msba5P>JnWS:XuCf.yM<o})/xd<4qMzt-D|v.');
define('NONCE_KEY',        '[+Y;Tp]u2lCU~k1HHO^+VkWeM-=E[_qJrzI!`2qE2[*?^r{!0cesiy<LKbNZ+{0}');
define('AUTH_SALT',        'Xi8dJ,{ac|4h#JNU4|OW-GSF,M.d:xkx/l&^;myS$#5NaLNWqCrF@h~HyLJ1mJ&:');
define('SECURE_AUTH_SALT', '_%ql4?8c+UY<Qa;-X-$H-f~:=-*VAa4V,&!,LG{@fbATOk_JzSW_^yjXlp6M8Gg%');
define('LOGGED_IN_SALT',   'o:|BEBBOv,ACU`gLfH>z6gDVs<b(XZ:WPLvS[iF2OW%_rQ* >kLA4n-C9arfoq;{');
define('NONCE_SALT',       '`UG.URn6G-@l3k=w&4OgN>>Ar+%RX<gvV-S?FX373=s9T*ii Tb^PKJcU< Ov@*9');

$table_prefix = 'wp_';

define( 'WP_DEBUG', true );

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';