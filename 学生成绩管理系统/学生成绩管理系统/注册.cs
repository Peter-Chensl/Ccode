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

namespace 学生成绩管理系统
{
    public partial class 注册 : Form
    {
        public 注册()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
            登录 form = new 登录();
            form.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String username, password, repassword;
            username = textBox1.Text;
            password = textBox2.Text;
            repassword = textBox3.Text;
            string comm = "server = localhost;port=3306;user=root;password=123456;database=score";
            MySqlConnection sq = new MySqlConnection(comm);
            if (comboBox1.Text == "学生")
            {
                if (username == "")
                {
                    MessageBox.Show("用户名不能为空！");
                    return;
                }
                if (textBox4.Text == "")
                {
                    MessageBox.Show("班级不能为空!");
                    return;
                }
                if (password == "")
                {
                    MessageBox.Show("密码不能为空!");
                    return;
                }
                if (repassword == "")
                {
                    MessageBox.Show("确认密码不能为空!");
                    return;
                }
                if (password != repassword)
                {
                    MessageBox.Show("密码和确认密码不相符!");
                    password = "";
                    repassword = "";
                    return;
                }
                try
                {
                    string sql = string.Format("select count(*) from student where sname='{0}'", username);
                    MySqlCommand cmd = new MySqlCommand(sql, sq);

                    sq.Open();
                    int a = Convert.ToInt32(cmd.ExecuteScalar());//返回一个值，看用户是否存在

                    if (a == 0)
                    {

                        sql = "INSERT INTO student(sname,class,password) VALUES('" + username + "','" +textBox4.Text + "','" + password + "')";
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

                catch (Exception ex)
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
            if (comboBox1.Text == "教师")
            {
                if (username == "")
                {
                    MessageBox.Show("用户名不能为空！");
                    return;
                }
                if (textBox4.Text == "")
                {
                    MessageBox.Show("科目不能为空!");
                    return;
                }
                if (password == "")
                {
                    MessageBox.Show("密码不能为空!");
                    return;
                }
                if (repassword == "")
                {
                    MessageBox.Show("确认密码不能为空!");
                    return;
                }
                if (password != repassword)
                {
                    MessageBox.Show("密码和确认密码不相符!");
                    password = "";
                    repassword = "";
                    return;
                }
                try
                {
                    string sql = string.Format("select count(*) from techer where tname='{0}'", username);
                    MySqlCommand cmd = new MySqlCommand(sql, sq);

                    sq.Open();
                    int a = Convert.ToInt32(cmd.ExecuteScalar());//返回一个值，看用户是否存在

                    if (a == 0)
                    {

                        sql = "INSERT INTO techer(tname,tobject,tphone,tpassword) VALUES('" + username + "','" + textBox5.Text + "','" + textBox6.Text + "','" + password + "')";
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

                catch (Exception ex)
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
            if (comboBox1.Text == "管理员")
            {
                if (username == "")
                {
                    MessageBox.Show("用户名不能为空！");
                    return;
                }
                if (textBox4.Text == "")
                {
                    MessageBox.Show("班级不能为空!");
                    return;
                }
                if (password == "")
                {
                    MessageBox.Show("密码不能为空!");
                    return;
                }
                if (repassword == "")
                {
                    MessageBox.Show("确认密码不能为空!");
                    return;
                }
                if (password != repassword)
                {
                    MessageBox.Show("密码和确认密码不相符!");
                    password = "";
                    repassword = "";
                    return;
                }
                try
                {
                    string sql = string.Format("select count(*) from master where maname='{0}'", username);
                    MySqlCommand cmd = new MySqlCommand(sql, sq);

                    sq.Open();
                    int a = Convert.ToInt32(cmd.ExecuteScalar());//返回一个值，看用户是否存在

                    if (a == 0)
                    {

                        sql = "INSERT INTO master(mname,password) VALUES('" + username + "','"  + password + "')";
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

                catch (Exception ex)
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
        }
    }
}
