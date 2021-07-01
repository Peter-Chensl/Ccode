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

namespace work
{
    public partial class Lign_up : Form
    {
        public Lign_up()
        {
            InitializeComponent();
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void Lign_up_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)//注册
        {
            String username, password,repassword,email;
            String sex = comboBoxsex.Text;
            username = textBox1.Text;
            email = textEmail.Text;
            password = textBox2.Text;
            repassword = textBox3.Text;
            string comm = "server = localhost;port=3306;user=root;password=123456;database=book";
            MySqlConnection sq = new MySqlConnection(comm);
            if(username=="")
            {
                MessageBox.Show("用户名不能为空！");
                return;
            }
            if(password=="")
            {
                MessageBox.Show("密码不能为空!");
                return;
            }
            if(repassword=="")
            {
                MessageBox.Show("确认密码不能为空!");
                return;
            }
            if(password!=repassword)
            {
                MessageBox.Show("密码和确认密码不相符!");
                password= "";
                repassword = "";
                return;
            }
            try
            {
                string sql = string.Format("select count(*) from users where user_name='{0}'", username);
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                
                sq.Open();
                int a = Convert.ToInt32(cmd.ExecuteScalar());//返回一个值，看用户是否存在
              
                if (a==0)
                {
                  
                    sql = "INSERT INTO users(user_name,sex,email,password) VALUES('" + username + "','" + sex + "','" + email + "','" + password + "')";
                    MySqlCommand command = new MySqlCommand(sql, sq);
                
                    command.ExecuteNonQuery();
                        
                        MessageBox.Show("注册成功！", "信息提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                        this.Close();
                    
                }
                else
                {
                    MessageBox.Show("用户已存在！", "信息提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    this.Close();
                }
                
 
            }
 
            catch(Exception ex)
            {
                MessageBox.Show(ex.ToString());
                Application.Exit();
            }
 
            finally
            {
                sq.Close();
                sq.Dispose();
            }

        }

        private void button2_Click(object sender, EventArgs e)//返回登录
        {
            this.Close();
            登录 form = new 登录();
            form.Show();
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
