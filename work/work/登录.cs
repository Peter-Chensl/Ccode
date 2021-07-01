using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;
using MySql.Data;

namespace work
{
    public partial class 登录 : Form
    {
        public 登录()
        {
            InitializeComponent();
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void sign_in_Click(object sender, EventArgs e)
        {
            String username, password;
            username = txtName.Text;
            password = txtpsd.Text;
            
            String myconn = "server = localhost;port=3306;user=root;password=123456;database=book";//数据库实例连接字符串
            MySqlConnection sq = new MySqlConnection(myconn);//建立连接
            sq.Open();//打开数据库
            string sql = string.Format("select count(*) from users where user_name='{0}'", username);
            MySqlCommand cmd = new MySqlCommand(sql, sq);
            int a = Convert.ToInt32(cmd.ExecuteScalar());//返回一个值，看用户是否存在
            string sql1 = string.Format("select count(*) from users where password='{0}'", password);
            MySqlCommand cmd1 = new MySqlCommand(sql1, sq);
            int b = Convert.ToInt32(cmd1.ExecuteScalar());
            if(a !=0 &&b!=0)
            {
                Form1 form = new Form1();
                form.Show();
            }
            else
            {
                DialogResult dr = MessageBox.Show("请检查您的用户名或密码是否正确，或注册新用户！","登录失败!",MessageBoxButtons.YesNo,MessageBoxIcon.Question);
                if(dr == DialogResult.Yes)//打开注册页面
                {
                    Lign_up form2 = new Lign_up();
                    form2.Show();
                }
                else
                {
                    this.Show();
                }

            }


        }

        private void sign_up_Click(object sender, EventArgs e)
        {
            Lign_up form2 = new Lign_up();
            form2.Show();
        } 
    }
}
